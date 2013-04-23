/*
 * LM4 GPIO Register Definitions
 *
 * This file is a part of libperipha library:
 * https://github.com/pfalcon/libperipha
 *
 * Copyright (c) 2013 Paul Sokolovsky
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Paul Sokolovsky nor the names of other contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <libperipha_types.h>

#define RESERVED(no, type, before_off, after_off) type reserved##no ((after_off - before_off) / sizeof(type) - 1)

// Pins per port: 8
struct GPIO_ {
    __rw uint32_t DATA;
    RESERVED(0, uint32_t, 0x000, 0x400);
    __rw uint32_t DIR;
    __ro uint32_t IS;
    __rw uint32_t IBE;
    __rw uint32_t IEV;
    __rw uint32_t IM;
    __ro uint32_t RIS;
    __ro uint32_t MIS;
    __rw uint32_t ICR;
    __rw uint32_t AFSEL;
    RESERVED(1, uint32_t, 0x420, 0x500);
};

#define GPIOA_APB_BASE 0x40004000
#define GPIOB_APB_BASE 0x40005000
#define GPIOC_APB_BASE 0x40006000
#define GPIOD_APB_BASE 0x40007000

#define GPIOE_APB_BASE 0x40024000
#define GPIOE_APB_BASE 0x40025000

#define GPIOA ((struct GPIO_*)GPIOA_APB_BASE)
#define GPIOB ((struct GPIO_*)GPIOB_APB_BASE)
#define GPIOC ((struct GPIO_*)GPIOC_APB_BASE)
#define GPIOD ((struct GPIO_*)GPIOD_APB_BASE)
#define GPIOE ((struct GPIO_*)GPIOE_APB_BASE)
#define GPIOF ((struct GPIO_*)GPIOF_APB_BASE)
#define GPIOG ((struct GPIO_*)GPIOG_APB_BASE)
