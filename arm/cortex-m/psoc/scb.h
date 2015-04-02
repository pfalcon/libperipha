/*
 * This file is part of the libperipha library:
 * https://github.com/pfalcon/libperipha
 *
 * Copyright (c) 2014 Paul Sokolovsky
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
 * @see PSOC4_SCB
 */

/** Definitions for the SCB subsystem (PSOC4 SCB Component).
 *
 * This corresponds to the description in
 * PSoC_4100_4200_Family_TRM_001-85847.pdf section 16.
 *
 * @ingroup PSOC4
 * @defgroup PSOC4_SCB SCB (PSOC4 SCB Component)
 * @{
 */

#ifndef LIBPERIPHA_PSOC4_SCB_H
#define LIBPERIPHA_PSOC4_SCB_H

/** Register definitions and register value definitions for the SCB subsystem
 *
 * @defgroup PSOC4_SCB_regsandvals SCB registers and values
 * @{
 */

/** These definitions reflect PSoC_4100_4200_Family_TRM_001-85847.pdf section
 * 16.1
 *
 * @defgroup PSOC4_SCB_registers SCB registers
 * @{
 */

typedef struct SCB__ {
__rw uint32_t CTRL; /**< @see PSOC4_SCB_CTRL_bits */
__rw uint32_t STATUS;
uint32_t RESERVED0[6];
__rw uint32_t SPI_CTRL;
__rw uint32_t SPI_STATUS;
uint32_t RESERVED1[6];
__rw uint32_t UART_CTRL; /**< @see PSOC4_SCB_UART_CTRL_bits */
__rw uint32_t UART_TX_CTRL; /**< @see PSOC4_SCB_UART_TX_CTRL_bits */
__rw uint32_t UART_RX_CTRL;
__rw uint32_t UART_RX_STATUS;
uint32_t RESERVED2[4];
__rw uint32_t I2C_CTRL;
__rw uint32_t I2C_STATUS;
__rw uint32_t I2C_M_CMD;
__rw uint32_t I2C_S_CMD;
__rw uint32_t I2C_CFG;
} SCB_Type;

/** @} */

/** Bit states for the SCB_CTRL register
 *
 * See PSoC_4100_4200_Family_TRM_001-85847.pdf section 16?definition_baserefext?
 * for definitions.
 *
 * @defgroup PSOC4_SCB_CTRL_bits SCB CTRL bits
 * @{
 */

#define SCB_CTRL_ENABLED        (1<<31)
#define SCB_CTRL_MODE_MASK      (0x3<<24)
#define SCB_CTRL_OVS_MASK       (0xf<<0)

/** @} */

/** Bit states for the SCB_UART_CTRL register
 *
 * See PSoC_4100_4200_Family_TRM_001-85847.pdf section 16?definition_baserefext?
 * for definitions.
 *
 * @defgroup PSOC4_SCB_UART_CTRL_bits SCB UART_CTRL bits
 * @{
 */

#define SCB_UART_CTRL_MODE_STD  (0<<24)
#define SCB_UART_CTRL_MODE_SMARTCARD (1<<24)
#define SCB_UART_CTRL_MODE_IRDA (2<<24)
#define SCB_UART_CTRL_MODE_MASK (0x3<<24)
#define SCB_UART_CTRL_LOOPBACK  (1<<16)

/** @} */

/** Bit states for the SCB_UART_TX_CTRL register
 *
 * See PSoC_4100_4200_Family_TRM_001-85847.pdf section 16?definition_baserefext?
 * for definitions.
 *
 * @defgroup PSOC4_SCB_UART_TX_CTRL_bits SCB UART_TX_CTRL bits
 * @{
 */

#define SCB_UART_TX_CTRL_STOP_BITS_MASK (0x7<<0)

/** @} */

/** @} */

#define SCB_BASE 0x40060000
#define SCB ((SCB_Type*)SCB_BASE)

/** @} */

#endif
