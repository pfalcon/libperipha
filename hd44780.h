/*
 * Hitachi HD44780 LCD Controller Register Definitions
 * http://en.wikipedia.org/wiki/Hitachi_HD44780_LCD_controller
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

#define HD44780_CMD_CLS        0x01
#define HD44780_CMD_HOME       0x02
#define HD44780_CMD_ENTRY_MODE 0x04

// Display Features On/Off Control
#define HD44780_CMD_DISP_CTRL  0x08

// Shift cursor or display w/o changing content
#define HD44780_CMD_SHIFT      0x10

// Function set. p.27 "Perform the function at the head of the program
// before executing any instructions (except for the read busy flag and
// address instruction)."
#define HD44780_CMD_FUNC_SET   0x20
#define HD44780_CMD_SET_CGRAM  0x40
// p.29 "when N is 0 (1-line display), AAAAAAA can be 00H to 4FH. When N is 1 (2-line display),
// AAAAAAA can be 00H to 27H for the first line, and 40H to 67H for the second line.""
#define HD44780_CMD_SET_DDRAM  0x80

#define HD44780_ENTRY_CURSOR   0x00
#define HD44780_ENTRY_DISPLAY  0x01
#define HD44780_ENTRY_DEC      0x00
#define HD44780_ENTRY_INC      0x02

#define HD44780_SHIFT_CURSOR   0x00
#define HD44780_SHIFT_DISPLAY  0x08
#define HD44780_SHIFT_LEFT     0x00
#define HD44780_SHIFT_RIGHT    0x04

#define HD44780_CTRL_BLINK_ON  0x01
#define HD44780_CTRL_CURSOR_ON 0x02
#define HD44780_CTRL_DISP_ON   0x04

#define HD44780_FUNC_DL4       0x00
#define HD44780_FUNC_DL8       0x10
#define HD44780_FUNC_NLINES1   0x00
#define HD44780_FUNC_NLINES2   0x08
#define HD44780_FUNC_F5x8      0x00
#define HD44780_FUNC_F5x10     0x04
