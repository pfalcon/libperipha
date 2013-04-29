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
 * @see LM4_UART
 */

/** Definitions for the UART subsystem (LM4 UART Component).
 *
 * This corresponds to the description in ?baseref?.
 *
 * @ingroup LM4
 * @defgroup LM4_UART UART (LM4 UART Component)
 * @{
 */

#ifndef LIBPERIPHA_EFM32_TINYGECKO_UART_H
#define LIBPERIPHA_EFM32_TINYGECKO_UART_H

/** Register definitions and register value definitions for the UART subsystem
 *
 * @defgroup LM4_UART_regsandvals UART registers and values
 * @{
 */

/** These definitions reflect ?baseref??registers_baserefext?
 *
 * @defgroup LM4_UART_registers UART registers
 * @{
 */

typedef struct UART {
__rw uint32_t DR;
__rw uint32_t RSR;
uint32_t RESERVED0[4];
__ro uint32_t FR;
uint32_t RESERVED1[1];
__rw uint32_t ILPR;
__rw uint32_t IBRD;
__rw uint32_t FBRD;
__rw uint32_t LCR_H;
__rw uint32_t CR;
__rw uint32_t IFLS;
__rw uint32_t IMSC;
__ro uint32_t RIS;
__ro uint32_t MIS;
__wo uint32_t ICR;
__rw uint32_t DMACR;
uint32_t RESERVED2[991];
__rw uint32_t CC;
uint32_t RESERVED3[5];
__ro uint32_t PeriphID0;
__ro uint32_t PeriphID1;
__ro uint32_t PeriphID2;
__ro uint32_t PeriphID3;
__ro uint32_t PCellID0;
__ro uint32_t PCellID1;
__ro uint32_t PCellID2;
__ro uint32_t PCellID3;
} UART_Type;

/** @} */

/** @} */

#define UART0_BASE 0x4000c000
#define UART0 ((UART_Type*)UART0_BASE)

/** @} */

#endif
