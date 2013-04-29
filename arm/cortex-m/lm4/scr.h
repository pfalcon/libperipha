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
 * @see LM4_SCR
 */

/** Definitions for the SCR subsystem (LM4 System Control Registers Component).
 *
 * This corresponds to the description in lm4f120h5qr.pdf section 5.
 *
 * @ingroup LM4
 * @defgroup LM4_SCR SCR (LM4 System Control Registers Component)
 * @{
 */

#ifndef LIBPERIPHA_EFM32_TINYGECKO_SCR_H
#define LIBPERIPHA_EFM32_TINYGECKO_SCR_H

/** Register definitions and register value definitions for the SCR subsystem
 *
 * @defgroup LM4_SCR_regsandvals SCR registers and values
 * @{
 */

/** These definitions reflect lm4f120h5qr.pdf section 5.5
 *
 * @defgroup LM4_SCR_registers SCR registers
 * @{
 */

typedef struct SCR {
uint32_t RESERVED0[386];
__rw uint32_t RCGCGPIO;
uint32_t RESERVED1[255];
__rw uint32_t PRGPIO;
} SCR_Type;

/** @} */

/** @} */

#define SCR_BASE 0x400fe000
#define SYSCTL_BASE 0x400fe000
#define SCR ((SCR_Type*)SCR_BASE)
#define SYSCTL ((SCR_Type*)SYSCTL_BASE)

/** @} */

#endif
