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
 * @see NRF51_GPIO
 */

/** Definitions for the GPIO subsystem (nRF51 GPIO Component).
 *
 * This corresponds to the description in nRF51_Reference_manual v1.1.pdf
 * section 13.
 *
 * @ingroup nRF51
 * @defgroup NRF51_GPIO GPIO (nRF51 GPIO Component)
 * @{
 */

#ifndef LIBPERIPHA_EFM32_TINYGECKO_GPIO_H
#define LIBPERIPHA_EFM32_TINYGECKO_GPIO_H

/** Register definitions and register value definitions for the GPIO subsystem
 *
 * @defgroup NRF51_GPIO_regsandvals GPIO registers and values
 * @{
 */

/** These definitions reflect nRF51_Reference_manual v1.1.pdf section 13.2
 *
 * @defgroup NRF51_GPIO_registers GPIO registers
 * @{
 */

typedef struct GPIO__ {
uint32_t RESERVED0[321];
__rw uint32_t OUT;
__rw uint32_t OUTSET;
__rw uint32_t OUTCLR;
__rw uint32_t IN;
__rw uint32_t DIR;
__rw uint32_t DIRSET;
__rw uint32_t DIRCLR;
uint32_t RESERVED1[120];
__rw uint32_t PIN_CNF; /**< @see NRF51_GPIO_PIN_CNF_bits */
} GPIO_Type;

/** @} */

/** Bit states for the GPIO_PIN_CNF register
 *
 * See nRF51_Reference_manual v1.1.pdf section 13?definition_baserefext? for
 * definitions.
 *
 * @defgroup NRF51_GPIO_PIN_CNF_bits GPIO PIN_CNF bits
 * @{
 */

#define GPIO_PIN_CNF_DIR        (1<<0)
#define GPIO_PIN_CNF_INPUT      (1<<1)
#define GPIO_PIN_CNF_PULL_DISABLED (0<<2)
#define GPIO_PIN_CNF_PULL_PULLDOWN (1<<2)
#define GPIO_PIN_CNF_PULL_PULLUP (2<<2)
#define GPIO_PIN_CNF_PULL_MASK  (0x3<<2)
#define GPIO_PIN_CNF_DRIVE_S0S1 (0<<8)
#define GPIO_PIN_CNF_DRIVE_H0S1 (1<<8)
#define GPIO_PIN_CNF_DRIVE_S0H1 (2<<8)
#define GPIO_PIN_CNF_DRIVE_H0H1 (3<<8)
#define GPIO_PIN_CNF_DRIVE_D0S1 (4<<8)
#define GPIO_PIN_CNF_DRIVE_D0H1 (5<<8)
#define GPIO_PIN_CNF_DRIVE_S0D1 (6<<8)
#define GPIO_PIN_CNF_DRIVE_H0D1 (7<<8)
#define GPIO_PIN_CNF_DRIVE_MASK (0x7<<8)
#define GPIO_PIN_CNF_SENSE_DISABLED (0<<16)
#define GPIO_PIN_CNF_SENSE_HIGH (1<<16)
#define GPIO_PIN_CNF_SENSE_LOW  (2<<16)
#define GPIO_PIN_CNF_SENSE_MASK (0x3<<16)

/** @} */

/** @} */

#define GPIO_P0_BASE 0x50000000
#define GPIO_P0 ((GPIO_Type*)GPIO_P0_BASE)

/** @} */

#endif
