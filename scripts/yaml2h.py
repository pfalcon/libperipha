#
# YAML to C headers generator
#
# Copyright (c) 2012 chrysn <chrysn@fsfe.org>
# Copyright (c) 2013 Paul Sokolovsky <pfalcon@users.sourceforge.net>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
# 3. Neither the name of Paul Sokolovsky nor the names of other contributors
# may be used to endorse or promote products derived from this software
# without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
# IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
# PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
# TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#!/usr/bin/env python

import sys
import os
import yaml
import logging
import textwrap
import glob


USE_LIBOPENCM3 = 0

def length2type(bits):
    return {8: "uint8_t", 16: "uint16_t", 32: "uint32_t"}[bits]

def commentblock(*textblocks, **formatargs):
    ret = []
    nowrapcommands = set("@defgroup")
    ret.extend(textwrap.wrap(textblocks[0].format(**formatargs), 80, initial_indent="/** ", subsequent_indent=" * "))
    last_block_was_at = textblocks[0].startswith('@')
    for b in textblocks[1:]:
        formatted = b.format(**formatargs)

        if not (last_block_was_at and b.startswith('@')):
            ret.append(" *")
        if any(b.startswith(c) for c in nowrapcommands):
            ret.append(" * " + formatted)
        else:
            ret.extend(textwrap.wrap(formatted, 80, initial_indent=" * ", subsequent_indent=" * "))
        last_block_was_at = b.startswith('@')
    return "\n".join(ret) + "\n */\n"

def add_defaults(data):
    reg_defaults = data.get('register defaults', {})
    for regdata in data['registers']:
        for k, v in reg_defaults.iteritems():
                if k not in regdata:
                    regdata[k] = v

def load_inherit(fname):
    data = yaml.load(open(os.path.join(base_dir, fname + ".yaml")))
    add_defaults(data)
    regs = data['registers']
    for i in data.get('inherit', []):
        regs += load_inherit(i)
    return regs


reserved_cnt = 0
def yaml2h(filenamebase, as_struct=False):
    global reserved_cnt
    headername = "%s.h"%filenamebase
    yamlname = "%s.yaml"%filenamebase
    conveniencename = "%s.convenienceheaders"%filenamebase

    logging.info("Generating %s from %s", headername, yamlname)

    data = yaml.load(open(yamlname))
    add_defaults(data)
    for i in data.get('inherit', []):
        data['registers'] += load_inherit(i)
    # some defaults
    data.setdefault("projectname", "libperipha")
    data.setdefault("includeguard", "LIBPERIPHA_EFM32_TINYGECKO_%s_H"%data['shortname'])
    data.setdefault("baseref", "?baseref?")
    data.setdefault("registers_baserefext", "?registers_baserefext?")
    data.setdefault("ingroup", "?ingroup?")

    with open(headername, 'w') as outfile:
        def wc(*args, **kwargs): # wrap "outfile" and "data" (as default) arguments  -- i'm a lazy typer
            final_kwargs = data.copy()
            final_kwargs.update(kwargs)
            outfile.write(commentblock(*args, **final_kwargs))
        def wc_close():
            outfile.write("/** @} */\n")
        def nl(): outfile.write("\n")
        def define(key, value, comment=None):
            outfile.write("#define ")
            outfile.write(key)
            outfile.write(" "*max(24-len(key), 1))
            outfile.write(str(value))
            if comment is not None:
                outfile.write(" /**< %s */"%comment)
            nl()
        def struct_field(access, length, key, comment=None):
            outfile.write("__" + access + " ")
            outfile.write(length2type(length) + " ")
            outfile.write(key)
            outfile.write(";")
            if comment is not None:
                outfile.write(" /**< %s */"%comment)
            nl()
        def struct_reserved(byte_size, type_len=32):
            global reserved_cnt
            assert byte_size % ((type_len / 8)) == 0
            outfile.write("%s RESERVED%d[%d];" % (length2type(type_len), reserved_cnt, byte_size / (type_len / 8)))
            nl()
            reserved_cnt += 1

        outfile.write(licensedata[data['license']].format(**data))

        if as_struct:
            outfile.write("#include <libperipha_types.h>")
            nl()

        nl()
        wc("@file", "@see {shortdocname}")
        nl()
        wc("Definitions for the {shortname} subsystem ({longname}).", "This corresponds to the description in {baseref}.", "@ingroup {ingroup}", "@defgroup {shortdocname} {shortname} ({longname})", "@{{")
        nl()
        outfile.write("#ifndef {includeguard}\n#define {includeguard}\n".format(**data))
        nl()
        if USE_LIBOPENCM3:
            outfile.write("#include <libopencm3/cm3/common.h>\n#include <libopencm3/efm32/memorymap.h>\n")
            nl()
        wc("Register definitions and register value definitions for the {shortname} subsystem", "@defgroup {shortdocname}_regsandvals {shortname} registers and values", "@{{")
        nl()

        regs = data['registers']

        for template in data.get('templateregs', []):
            template['is_template'] = []
            regs.append(template)

        regs_dict = dict((x['name'], x) for x in regs) # for easier access. they've got to be a list in yaml to preserve order

        wc("These definitions reflect {baseref}{registers_baserefext}", "@defgroup {shortdocname}_registers {shortname} registers", "@{{")
        nl()

        if as_struct:
            outfile.write("typedef struct " + data['shortname'] + " {");
            nl()

        reserved_cnt = 0
        offset = 0

        regs.sort(lambda a, b: cmp(a["offset"], b["offset"]))

        for regdata in regs:
            has_bits = "fields" in regdata
            has_values = "values" in regdata
            is_template = "is_template" in regdata
            if is_template:
                # this isn't a real register, just a template
                continue

            assert regdata["offset"] >= offset, regdata
            if as_struct and regdata["offset"] > offset:
                struct_reserved(regdata["offset"] - offset)
            offset = regdata["offset"] + regdata.get('length', 32) / 8

            secondcomponent_name = regdata['name']
            if (has_bits and isinstance(regdata['fields'], str)) or (has_values and isinstance(regdata['values'], str)):
                # uses a template
                secondcomponent_name = regdata['fields'] if has_bits else regdata['values']
                regs_dict[secondcomponent_name]['is_template'].append(regdata['name'])

            comment = None
            if has_bits or has_values:
                comment = "@see %s_%s_%s" % (data['shortdocname'], secondcomponent_name, 'values' if 'values' in regdata else 'bits')

            if as_struct:
                if 'length' not in regdata:
                    print "Warning: register %s lacks 'length' property, assumed 32" % regdata['name']
                if 'access' not in regdata:
                    print "Warning: register %s lacks 'access' property, assumed 'rw'" % regdata['name']
                struct_field(regdata.get('access', 'rw'), regdata.get('length', 32), regdata['name'], comment)
            else:
                define("%s_%s" % (data['shortname'], regdata['name']),
                       "MMIO32(%s_BASE + %#.003x)" % (data['shortname'], regdata['offset']),
                       comment)

        if as_struct:
            outfile.write("} " + data['shortname'] + "_Type;");
            nl()

        nl()
        wc_close() # close register definitions
        nl()

        for regdata in regs:
            has_bits = "fields" in regdata
            has_values = "values" in regdata
            is_template = "is_template" in regdata
            if not has_bits and not has_values:
                continue

            if (has_bits and isinstance(regdata['fields'], str)) or (has_values and isinstance(regdata['values'], str)):
                # uses a template, doesn't need own section
                continue

            commentlines = []
            if is_template:
                commentlines.append("%s for the {shortname} \"{name}\" group of registers (%s)"%("Bit states" if has_bits else "Values", ", ".join(regdata['is_template'])))
                assert len(regdata['is_template']) > 0, "What should I talk about when nobody uses this template?"
                if 'override_backref' in regdata:
                    commentlines.append(regdata['override_backref'])
                else:
                    commentlines.append("These registers use this:")
                    commentlines.append("<ul>") # FIXME: once we're using markdown 1.8, this can be changed to markdown
                    for user in regdata['is_template']:
                        userdata = regs_dict[user]
                        # FIXME: this is an ugly hack around this being in a single wc() line which doesn't take per-line contexts
                        mergeddata = data.copy()
                        mergeddata.update(userdata)
                        commentlines.append(("<li>The {shortname}_{name} register; see {baseref}{definition_baserefext} for definitions"+regdata.get("details", "."+"</li>")).format(**mergeddata))
                    commentlines.append("</ul>")
                commentlines.append('@defgroup {shortdocname}_{name}_%s {shortname} {name} %s'%(('bits' if has_bits else 'values', 'bits group' if has_bits else 'values group')))
            else:
                commentlines.append("%s for the {shortname}_{name} register"%("Bit states" if has_bits else "Values"))
                commentlines.append("See {baseref}{definition_baserefext} for definitions"+regdata.get("details", "."))
                commentlines.append('@defgroup {shortdocname}_{name}_%s {shortname} {name} %s'%(('bits' if has_bits else 'values',)*2))
            commentlines.append('@{{')
            wc(*commentlines, **regdata)
            nl()

            if has_bits:
                for field in regdata['fields']:
                    #shiftdefine = "_%s_%s_%s_shift"%(shortname, regdata['name'], field['name'])
                    #define(shiftdefine, field['shift'])

                    # there is one condition under which field's doc would get shown; show it immediately otherwise
                    if 'doc' in field and not ("values" not in field and field.get("length", 1) == 1):
                        wc(field['doc'])

                    if "values" in field:
                        for value in field.get("values"):
                            define("%s_%s_%s_%s"%(data['shortname'], regdata['name'], field['name'], value['name']), value['value'] if "mask" in field else "(%s<<%s)"%(value['value'], field['shift']), value.get('doc', None))
                    else:
                        if field.get('length', 1) == 1:
                            define("%s_%s_%s"%(data['shortname'], regdata['name'], field['name']), "(1<<%s)"%field['shift'], field.get('doc', None))
                        else:
                            # FIXME: this should require the 'type' parameter to be set on this field
                            pass

                    if "values" in field or field.get("length", 1) != 1:
                        if "mask" in field:
                            mask = field['mask']
                        else:
                            mask = "(%#x<<%s)"%(~(~0<<field.get('length', 1)), field['shift'])
                        define("%s_%s_%s_MASK"%(data['shortname'], regdata['name'], field['name']), mask)
            else:
                for value in regdata['values']:
                    define("%s_%s_%s"%(data['shortname'], regdata['name'], value['name']), value['value'], value.get('doc', None))

            nl()
            wc_close()
            nl()
        wc_close() # close registers and values
        nl()

        for comp in data.get('blocks', []):
            outfile.write("#define %s_BASE %#x\n" % (comp["name"], comp["base"]))

        for comp in data.get('blocks', []):
            outfile.write("#define %s ((%s_Type*)%s_BASE)\n" % (comp['name'], data['shortname'], comp['name']))

        if os.path.isfile(conveniencename):
            outfile.write(open(conveniencename).read())

        nl()
        wc_close() # close convenience
        nl()
        outfile.write("#endif\n")

if __name__ == "__main__":
    logging.basicConfig(level=logging.DEBUG)
    base_dir = sys.argv[1]
    licensedata = yaml.load(open(os.path.join(base_dir, "generate-license.yaml")))
    for fname in glob.glob("*.yaml"):
        basename = os.path.splitext(fname)[0]
        yaml2h(basename, True)
