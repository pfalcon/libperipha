/*
 * STM32 RCC (Reset & Clock Control) Register Definitions
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

struct RCC_ {
    __rw uint32_t CR;
    __rw uint32_t CFGR;
    __ro uint32_t CIR;
    __rw uint32_t APB2RSTR;
    __rw uint32_t APB1RSTR;
    __rw uint32_t AHBENR;
    __rw uint32_t APB2ENR;
    __rw uint32_t APB1ENR;
    __rw uint32_t BDCR;
    __rw uint32_t CSR;
};

#define RCC_APB2ENR_AFIOEN (1<<0)
#define RCC_APB2ENR_IOPAEN (1<<2)
#define RCC_APB2ENR_IOPBEN (1<<3)
#define RCC_APB2ENR_IOPCEN (1<<4)
#define RCC_APB2ENR_IOPDEN (1<<5)
#define RCC_APB2ENR_IOPEEN (1<<6)
#define RCC_APB2ENR_IOPFEN (1<<7)
#define RCC_APB2ENR_IOPGEN (1<<8)

#define RCC_BASE 0x40021000
