/*
 * STM32 GPIO Register Definitions
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

struct GPIO_ {
    __rw uint32_t CRL;
    __rw uint32_t CRH;
    // Pins per port: 16
    __ro uint32_t IDR;
    __rw uint32_t ODR;
    __rw uint32_t BSRR;
    __rw uint32_t BRR;
    __rw uint32_t LCKR;
};

typedef struct GPIO_ GPIO_TypeDef;

#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
#define GPIOC_BASE 0x40011000
#define GPIOD_BASE 0x40011400
#define GPIOE_BASE 0x40011800
#define GPIOF_BASE 0x40011C00
#define GPIOG_BASE 0x40012000

#define GPIOA ((struct GPIO_*)GPIOA_BASE)
#define GPIOB ((struct GPIO_*)GPIOB_BASE)
#define GPIOC ((struct GPIO_*)GPIOC_BASE)
#define GPIOD ((struct GPIO_*)GPIOD_BASE)
#define GPIOE ((struct GPIO_*)GPIOE_BASE)
#define GPIOF ((struct GPIO_*)GPIOF_BASE)
#define GPIOG ((struct GPIO_*)GPIOG_BASE)
