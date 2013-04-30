/*
 * This file is part of the libperipha library:
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

/** @file
 * @see LM4_GPIO
 */

/** Definitions for the GPIO subsystem (LM4 GPIO Component).
 *
 * This corresponds to the description in ?baseref?.
 *
 * @ingroup LM4
 * @defgroup LM4_GPIO GPIO (LM4 GPIO Component)
 * @{
 */

#ifndef LIBPERIPHA_EFM32_TINYGECKO_GPIO_H
#define LIBPERIPHA_EFM32_TINYGECKO_GPIO_H

/** Register definitions and register value definitions for the GPIO subsystem
 *
 * @defgroup LM4_GPIO_regsandvals GPIO registers and values
 * @{
 */

/** These definitions reflect ?baseref??registers_baserefext?
 *
 * @defgroup LM4_GPIO_registers GPIO registers
 * @{
 */

typedef struct GPIO__ {
__rw uint32_t DATA_START;
uint32_t RESERVED0[254];
__rw uint32_t DATA;
__rw uint32_t DIR;
__ro uint32_t IS;
__rw uint32_t IBE;
__rw uint32_t IEV;
__rw uint32_t IM;
__ro uint32_t RIS;
__ro uint32_t MIS;
__rw uint32_t ICR;
__rw uint32_t AFSEL;
uint32_t RESERVED1[62];
__rw uint32_t DEN;
uint32_t RESERVED2[3];
__rw uint32_t PCTL;
uint32_t RESERVED3[684];
__ro uint32_t PeriphID0;
__ro uint32_t PeriphID1;
__ro uint32_t PeriphID2;
__ro uint32_t PeriphID3;
__ro uint32_t PCellID0;
__ro uint32_t PCellID1;
__ro uint32_t PCellID2;
__ro uint32_t PCellID3;
} GPIO_Type;

/** @} */

/** @} */

#define GPIOA_BASE 0x40004000
#define GPIOB_BASE 0x40005000
#define GPIOC_BASE 0x40006000
#define GPIOD_BASE 0x40007000
#define GPIOE_BASE 0x40024000
#define GPIOF_BASE 0x40025000
#define GPIOA ((GPIO_Type*)GPIOA_BASE)
#define GPIOB ((GPIO_Type*)GPIOB_BASE)
#define GPIOC ((GPIO_Type*)GPIOC_BASE)
#define GPIOD ((GPIO_Type*)GPIOD_BASE)
#define GPIOE ((GPIO_Type*)GPIOE_BASE)
#define GPIOF ((GPIO_Type*)GPIOF_BASE)

/** @} */

#endif
