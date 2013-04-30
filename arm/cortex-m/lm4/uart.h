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

typedef struct UART__ {
__rw uint32_t DR;
__rw uint32_t RSR;
uint32_t RESERVED0[4];
__ro uint32_t FR; /**< @see LM4_UART_FR_bits */
uint32_t RESERVED1[1];
__rw uint32_t ILPR;
__rw uint32_t IBRD;
__rw uint32_t FBRD;
__rw uint32_t LCRH; /**< @see LM4_UART_LCRH_bits */
__rw uint32_t CR; /**< @see LM4_UART_CR_bits */
__rw uint32_t IFLS;
__rw uint32_t IMSC;
__ro uint32_t RIS;
__ro uint32_t MIS;
__wo uint32_t ICR;
__rw uint32_t DMACR;
uint32_t RESERVED2[991];
__rw uint32_t CC; /**< @see LM4_UART_CC_bits */
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

/** Bit states for the UART_FR register
 *
 * See ?baseref??definition_baserefext? for definitions.
 *
 * @defgroup LM4_UART_FR_bits UART FR bits
 * @{
 */

#define UART_FR_TXFE            (1<<7)
#define UART_FR_RXFF            (1<<6)
#define UART_FR_TXFF            (1<<5)
#define UART_FR_RXFE            (1<<4)
#define UART_FR_BUSY            (1<<3)
#define UART_FR_CTS             (1<<0)

/** @} */

/** Bit states for the UART_LCRH register
 *
 * See ?baseref??definition_baserefext? for definitions.
 *
 * @defgroup LM4_UART_LCRH_bits UART LCRH bits
 * @{
 */

#define UART_LCRH_WLEN_5        (0<<5)
#define UART_LCRH_WLEN_6        (1<<5)
#define UART_LCRH_WLEN_7        (2<<5)
#define UART_LCRH_WLEN_8        (3<<5)
#define UART_LCRH_WLEN_MASK     (0x3<<5)

/** @} */

/** Bit states for the UART_CR register
 *
 * See ?baseref??definition_baserefext? for definitions.
 *
 * @defgroup LM4_UART_CR_bits UART CR bits
 * @{
 */

#define UART_CR_RXE             (1<<9)
#define UART_CR_TXE             (1<<8)
#define UART_CR_UARTEN          (1<<0)

/** @} */

/** Bit states for the UART_CC register
 *
 * See ?baseref??definition_baserefext? for definitions.
 *
 * @defgroup LM4_UART_CC_bits UART CC bits
 * @{
 */

#define UART_CC_CS_SYSCLK       (0<<0)
#define UART_CC_CS_PIOSC        (5<<0)
#define UART_CC_CS_MASK         (0xf<<0)

/** @} */

/** @} */

#define UART0_BASE 0x4000c000
#define UART0 ((UART_Type*)UART0_BASE)

/** @} */

#endif
