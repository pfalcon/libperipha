import sys

type2size = {"u8": 1, "u16": 2, "u32": 4}


def parse(fname):
    inherits = []
    fields = []
    with open(fname) as f:
        for l in f:
            l = l.strip()
            if not l or l[0] == "#":
                continue
            cols = l.split(None)
            if cols[0] == "inherit":
                inherits.append(cols[1])
                continue
            props = {}
            props["access"] = cols[0]
            props["type"] = cols[1]
            props["name"] = cols[2]
            props["offset"] = int(cols[3], 0)
            fields.append(props)
#    print fields
    for fname in inherits:
        fields += parse(fname + ".layout")

    return fields


reserved_cnt = 0

def render_reserved(byte_size, type="u32"):
    global reserved_cnt
    print "%s RESERVED%d[%d];" % (type, reserved_cnt, byte_size / type2size[type])
    reserved_cnt += 1

def render_fields(fields):
    offset = 0
    for f in fields:
        assert f["offset"] >= offset
        if f["offset"] > offset:
            render_reserved(f["offset"] - offset)
        print "__%s %s %s;" % (f["access"], f["type"], f["name"]);
        offset = f["offset"] + type2size[f["type"]]



fields = parse(sys.argv[1])
render_fields(fields)
