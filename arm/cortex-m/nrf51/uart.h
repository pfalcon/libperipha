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
 * @see NRF51_UART
 */

/** Definitions for the UART subsystem (nRF51 UART Component).
 *
 * This corresponds to the description in nRF51_Reference_manual v1.1.pdf
 * section 27.
 *
 * @ingroup nRF51
 * @defgroup NRF51_UART UART (nRF51 UART Component)
 * @{
 */

#ifndef LIBPERIPHA_NRF51_UART_H
#define LIBPERIPHA_NRF51_UART_H

/** Register definitions and register value definitions for the UART subsystem
 *
 * @defgroup NRF51_UART_regsandvals UART registers and values
 * @{
 */

/** These definitions reflect nRF51_Reference_manual v1.1.pdf section 27.2
 *
 * @defgroup NRF51_UART_registers UART registers
 * @{
 */

typedef struct UART__ {
__rw uint32_t STARTRX;
__rw uint32_t STOPRX;
__rw uint32_t STARTTX;
__rw uint32_t STOPTX;
uint32_t RESERVED0[62];
__rw uint32_t RXDRDY;
uint32_t RESERVED1[4];
__rw uint32_t TXDRDY;
uint32_t RESERVED2[1];
__rw uint32_t ERROR;
uint32_t RESERVED3[119];
__rw uint32_t INTENSET;
__rw uint32_t INTENCLR;
uint32_t RESERVED4[93];
__rw uint32_t ERRORSRC;
uint32_t RESERVED5[31];
__rw uint32_t ENABLE;
uint32_t RESERVED6[1];
__rw uint32_t RSELRTS;
__rw uint32_t RSELTXD;
__rw uint32_t RSELCTS;
__rw uint32_t RSELRXD;
__rw uint32_t RXD;
__rw uint32_t TXD;
uint32_t RESERVED7[1];
__rw uint32_t BAUDRATE;
uint32_t RESERVED8[17];
__rw uint32_t CONFIG; /**< @see NRF51_UART_CONFIG_bits */
} UART_Type;

/** @} */

/** Bit states for the UART_CONFIG register
 *
 * See nRF51_Reference_manual v1.1.pdf section 27?definition_baserefext? for
 * definitions.
 *
 * @defgroup NRF51_UART_CONFIG_bits UART CONFIG bits
 * @{
 */

#define UART_CONFIG_HWFC        (1<<0)
#define UART_CONFIG_PARITY      (1<<1)
#define UART_CONFIG_RXPARITY_MANUAL (0<<2)
#define UART_CONFIG_RXPARITY_AUTO (1<<2)
#define UART_CONFIG_RXPARITY_MASK (0x1<<2)
#define UART_CONFIG_TXPARITY_MANUAL (0<<3)
#define UART_CONFIG_TXPARITY_AUTO (1<<3)
#define UART_CONFIG_TXPARITY_MASK (0x1<<3)

/** @} */

/** @} */

#define UART0_BASE 0x40002000
#define UART0 ((UART_Type*)UART0_BASE)

/** @} */

#endif
