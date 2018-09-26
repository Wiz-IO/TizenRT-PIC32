/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/************************************************************************************************
 * libc/misc/lib_crc16.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * References:
 *
 *   crc16_tab calculated by Mark G. Mendel, Network Systems Corporation.
 *   crc16part() logic derived from article Copyright (C) 1986 Stephen Satchell.
 *
 * "Programmers may incorporate any or all code into their programs,
 *  giving proper credit within the source. Publication of the
 *  source routines is permitted so long as proper credit is given
 *  to Stephen Satchell, Satchell Evaluations and Chuck Forsberg,
 *  Omen Technology."
 *
 * Re-released under the Modified BSD license which, I believe, is consistent with the
 * original authors' intent:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************************/

/************************************************************************************************
 * Included Files
 ************************************************************************************************/

#include <sys/types.h>
#include <stdint.h>
#include <crc16.h>

/************************************************************************************************
 * Private Data
 ************************************************************************************************/

/* crc16_tab calculated by Mark G. Mendel, Network Systems Corporation */

static uint16_t crc16_tab[256] = {
	0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
	0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
	0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
	0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
	0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
	0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
	0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
	0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
	0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
	0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
	0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
	0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
	0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
	0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
	0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
	0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
	0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
	0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
	0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
	0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
	0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
	0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
	0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
	0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
	0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
	0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
	0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
	0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
	0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
	0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
	0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
	0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

/************************************************************************************************
 * Public Functions
 ************************************************************************************************/
/************************************************************************************************
 * Name: crc16part
 *
 * Description:
 *   Continue CRC calculation on a part of the buffer.
 *
 ************************************************************************************************/

uint16_t crc16part(FAR const uint8_t *src, size_t len, uint16_t crc16val)
{
	size_t i;

	for (i = 0; i < len; i++) {
		crc16val = crc16_tab[((crc16val >> 8) & 255)] ^ (crc16val << 8) ^ src[i];
	}

	return crc16val;
}

/************************************************************************************************
 * Name: crc16
 *
 * Description:
 *   Return a 16-bit CRC of the contents of the 'src' buffer, length 'len'
 *
 ************************************************************************************************/

uint16_t crc16(FAR const uint8_t *src, size_t len)
{
	return crc16part(src, len, 0);
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/************************************************************************************************
 * libc/misc/lib_crc32.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2010-2011 Gregory Nutt. All rights reserved.
 *
 * The logic in this file was developed by Gary S. Brown:
 *
 *   COPYRIGHT (C) 1986 Gary S. Brown.  You may use this program, or code or tables
 *   extracted from it, as desired without restriction.
 *
 * First, the polynomial itself and its table of feedback terms.  The polynomial is:
 *
 *    X^32+X^26+X^23+X^22+X^16+X^12+X^11+X^10+X^8+X^7+X^5+X^4+X^2+X^1+X^0
 *
 * Note that we take it "backwards" and put the highest-order term in the lowest-order bit.
 * The X^32 term is "implied"; the LSB is the X^31 term, etc.  The X^0 term (usually shown
 * as "+1") results in the MSB being 1
 *
 * Note that the usual hardware shift register implementation, which is what we're using
 * (we're merely optimizing it by doing eight-bit chunks at a time) shifts bits into the
 * lowest-order term.  In our implementation, that means shifting towards the right.  Why
 * do we do it this way?  Because the calculated CRC must be transmitted in order from
 * highest-order term to lowest-order term.  UARTs transmit characters in order from LSB
 * to MSB.  By storing the CRC this way we hand it to the UART in the order low-byte to
 * high-byte; the UART sends each low-bit to hight-bit; and the result is transmission bit
 * by bit from highest- to lowest-order term without requiring any bit shuffling on our
 * part.  Reception works similarly
 *
 * The feedback terms table consists of 256, 32-bit entries.  Notes
 *
 * - The table can be generated at runtime if desired; code to do so is shown later.  It
 *   might not be obvious, but the feedback terms simply represent the results of eight
 *   shift/xor operations for all combinations of data and CRC register values
 *
 * - The values must be right-shifted by eight bits by the updcrc logic; the shift must
 *   be u_(bring in zeroes).  On some hardware you could probably optimize the shift in
 *   assembler by using byte-swap instructions polynomial $edb88320
  ************************************************************************************************/

/************************************************************************************************
 * Included Files
 ************************************************************************************************/

#include <sys/types.h>
#include <stdint.h>
#include <crc32.h>

/************************************************************************************************
 * Private Data
 ************************************************************************************************/

static const uint32_t crc32_tab[] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172, 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924, 0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0, 0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a, 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc, 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236, 0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2, 0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

/************************************************************************************************
 * Public Functions
 ************************************************************************************************/
/************************************************************************************************
 * Name: crc32part
 *
 * Description:
 *   Continue CRC calculation on a part of the buffer.
 *
 ************************************************************************************************/

uint32_t crc32part(FAR const uint8_t *src, size_t len, uint32_t crc32val)
{
	size_t i;

	for (i = 0; i < len; i++) {
		crc32val = crc32_tab[(crc32val ^ src[i]) & 0xff] ^ (crc32val >> 8);
	}
	return crc32val;
}

/************************************************************************************************
 * Name: crc32
 *
 * Description:
 *   Return a 32-bit CRC of the contents of the 'src' buffer, length 'len'
 *
 ************************************************************************************************/

uint32_t crc32(FAR const uint8_t *src, size_t len)
{
	return crc32part(src, len, 0);
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/************************************************************************************************
 * libc/misc/lib_crc8.c
 *
 * This file is a part of NuttX:
 *
 *   Copyright (C) 2014 Ken Pettit. All rights reserved.
 *   Author: Ken Pettit <pettitkd@gmail.com>
 *
 * References:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************************/

/************************************************************************************************
 * Included Files
 ************************************************************************************************/

#include <sys/types.h>
#include <stdint.h>
#include <crc8.h>

/************************************************************************************************
 * Private Data
 *
 * CRC8 table generated with:
 *
 *   #define POLY 0xB2   // ((uint8_t)0x14D) ^ 0xFF
 *
 *   printf("    ");
 *   for (y=0; y<256; y++)
 *   {
 *     crc = y;
 *     for (x=0; x<8; x++)
 *       crc = (crc & 1) ? POLY ^ (crc >> 1) : crc >> 1;
 *     printf("0x%02X, ", crc);
 *     if ((y & 0x07) == 0x7)
 *       printf("\n    ");
 *   }
 *
 ************************************************************************************************/

static const uint8_t crc8_tab[256] = {
	0x00, 0x3e, 0x7c, 0x42, 0xf8, 0xc6, 0x84, 0xba,
	0x95, 0xab, 0xe9, 0xd7, 0x6d, 0x53, 0x11, 0x2f,
	0x4f, 0x71, 0x33, 0x0d, 0xb7, 0x89, 0xcb, 0xf5,
	0xda, 0xe4, 0xa6, 0x98, 0x22, 0x1c, 0x5e, 0x60,
	0x9e, 0xa0, 0xe2, 0xdc, 0x66, 0x58, 0x1a, 0x24,
	0x0b, 0x35, 0x77, 0x49, 0xf3, 0xcd, 0x8f, 0xb1,
	0xd1, 0xef, 0xad, 0x93, 0x29, 0x17, 0x55, 0x6b,
	0x44, 0x7a, 0x38, 0x06, 0xbc, 0x82, 0xc0, 0xfe,
	0x59, 0x67, 0x25, 0x1b, 0xa1, 0x9f, 0xdd, 0xe3,
	0xcc, 0xf2, 0xb0, 0x8e, 0x34, 0x0a, 0x48, 0x76,
	0x16, 0x28, 0x6a, 0x54, 0xee, 0xd0, 0x92, 0xac,
	0x83, 0xbd, 0xff, 0xc1, 0x7b, 0x45, 0x07, 0x39,
	0xc7, 0xf9, 0xbb, 0x85, 0x3f, 0x01, 0x43, 0x7d,
	0x52, 0x6c, 0x2e, 0x10, 0xaa, 0x94, 0xd6, 0xe8,
	0x88, 0xb6, 0xf4, 0xca, 0x70, 0x4e, 0x0c, 0x32,
	0x1d, 0x23, 0x61, 0x5f, 0xe5, 0xdb, 0x99, 0xa7,
	0xb2, 0x8c, 0xce, 0xf0, 0x4a, 0x74, 0x36, 0x08,
	0x27, 0x19, 0x5b, 0x65, 0xdf, 0xe1, 0xa3, 0x9d,
	0xfd, 0xc3, 0x81, 0xbf, 0x05, 0x3b, 0x79, 0x47,
	0x68, 0x56, 0x14, 0x2a, 0x90, 0xae, 0xec, 0xd2,
	0x2c, 0x12, 0x50, 0x6e, 0xd4, 0xea, 0xa8, 0x96,
	0xb9, 0x87, 0xc5, 0xfb, 0x41, 0x7f, 0x3d, 0x03,
	0x63, 0x5d, 0x1f, 0x21, 0x9b, 0xa5, 0xe7, 0xd9,
	0xf6, 0xc8, 0x8a, 0xb4, 0x0e, 0x30, 0x72, 0x4c,
	0xeb, 0xd5, 0x97, 0xa9, 0x13, 0x2d, 0x6f, 0x51,
	0x7e, 0x40, 0x02, 0x3c, 0x86, 0xb8, 0xfa, 0xc4,
	0xa4, 0x9a, 0xd8, 0xe6, 0x5c, 0x62, 0x20, 0x1e,
	0x31, 0x0f, 0x4d, 0x73, 0xc9, 0xf7, 0xb5, 0x8b,
	0x75, 0x4b, 0x09, 0x37, 0x8d, 0xb3, 0xf1, 0xcf,
	0xe0, 0xde, 0x9c, 0xa2, 0x18, 0x26, 0x64, 0x5a,
	0x3a, 0x04, 0x46, 0x78, 0xc2, 0xfc, 0xbe, 0x80,
	0xaf, 0x91, 0xd3, 0xed, 0x57, 0x69, 0x2b, 0x15
};

/************************************************************************************************
 * Public Functions
 ************************************************************************************************/
/************************************************************************************************
 * Name: crc8part
 *
 * Description:
 *   Continue CRC calculation on a part of the buffer.
 *
 ************************************************************************************************/

uint8_t crc8part(FAR const uint8_t *src, size_t len, uint8_t crc8val)
{
	size_t i;

	crc8val ^= 0xFF;
	for (i = 0; i < len; i++) {
		crc8val = crc8_tab[crc8val ^ src[i]];
	}

	return crc8val ^ 0xFF;
}

/************************************************************************************************
 * Name: crc8
 *
 * Description:
 *   Return a 8-bit CRC of the contents of the 'src' buffer, length 'len' using a CRC with
 *   the polynomial x^8+x^6+x^3+x^2+1 (Koopman, et al. "0xA6" polynomial).
 *
 ************************************************************************************************/

uint8_t crc8(FAR const uint8_t *src, size_t len)
{
	return crc8part(src, len, 0);
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * libc/misc/lib_dbg.c
 *
 *   Copyright (C) 2007-2009, 2011-2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdarg.h>
#include <debug.h>

#include "lib_internal.h"

#ifndef CONFIG_CPP_HAVE_VARARGS

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: dbg, lldbg, vdbg
 *
 * Description:
 *  If the cross-compiler's pre-processor does not support variable
 * length arguments, then these additional APIs will be built.
 *
 ****************************************************************************/

#ifdef CONFIG_DEBUG
int dbg(const char *format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = vsyslog(LOG_DEBUG, format, ap);
	va_end(ap);

	return ret;
}

#ifdef CONFIG_ARCH_LOWPUTC
int lldbg(const char *format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = lowvsyslog(LOG_DEBUG, format, ap);
	va_end(ap);

	return ret;
}
#endif

#ifdef CONFIG_DEBUG_VERBOSE
int vdbg(const char *format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = vsyslog(LOG_DEBUG, format, ap);
	va_end(ap);

	return ret;
}

#ifdef CONFIG_ARCH_LOWPUTC
int llvdbg(const char *format, ...)
{
	va_list ap;
	int ret;

	va_start(ap, format);
	ret = lowvsyslog(LOG_DEBUG, format, ap);
	va_end(ap);

	return ret;
}
#endif							/* CONFIG_ARCH_LOWPUTC */
#endif							/* CONFIG_DEBUG_VERBOSE */
#endif							/* CONFIG_DEBUG */
#endif							/* CONFIG_CPP_HAVE_VARARGS */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * libc/misc/lib_dumpbuffer.c
 *
 *   Copyright (C) 2009, 2011, 2014 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>
#include <tinyara/compiler.h>

#include <stdint.h>
#include <debug.h>

/****************************************************************************
 * Pre-processor definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_dumpbuffer
 *
 * Description:
 *  Do a pretty buffer dump
 *
 ****************************************************************************/

void lib_dumpbuffer(FAR const char *msg, FAR const uint8_t *buffer, unsigned int buflen)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	lowsyslog(LOG_INFO, "%s (%p):\n", msg, buffer);
	for (i = 0; i < buflen; i += 32) {
		lowsyslog(LOG_INFO, "%04x: ", i);
		for (j = 0; j < 32; j++) {
			k = i + j;

			if (j == 16) {
				lowsyslog(LOG_INFO, " ");
			}

			if (k < buflen) {
				lowsyslog(LOG_INFO, "%02x", buffer[k]);
			} else {
				lowsyslog(LOG_INFO, "  ");
			}
		}

		lowsyslog(LOG_INFO, " ");
		for (j = 0; j < 32; j++) {
			k = i + j;

			if (j == 16) {
				lowsyslog(LOG_INFO, " ");
			}

			if (k < buflen) {
				if (buffer[k] >= 0x20 && buffer[k] < 0x7f) {
					lowsyslog(LOG_INFO, "%c", buffer[k]);
				} else {
					lowsyslog(LOG_INFO, ".");
				}
			}
		}

		lowsyslog(LOG_INFO, "\n");
	}
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/************************************************************************
 * libc/misc/lib_filesem.c
 *
 *   Copyright (C) 2007, 2009, 2011 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <assert.h>

#include "lib_internal.h"

#if CONFIG_STDIO_BUFFER_SIZE > 0

/************************************************************************
 * Pre-processor Definitions
 ************************************************************************/

/************************************************************************
 * Private Data
 ************************************************************************/

/************************************************************************
 * Global Functions
 ************************************************************************/

/************************************************************************
 * lib_sem_initialize
 ************************************************************************/

void lib_sem_initialize(FAR struct file_struct *stream)
{
	/* Initialize the LIB semaphore to one (to support one-at-a-time access
	 * to private data sets.
	 */

	(void)sem_init(&stream->fs_sem, 0, 1);

	stream->fs_holder = -1;
	stream->fs_counts = 0;
}

/************************************************************************
 * lib_take_semaphore
 ************************************************************************/

void lib_take_semaphore(FAR struct file_struct *stream)
{
	pid_t my_pid = getpid();

	/* Do I already have the semaphore? */

	if (stream->fs_holder == my_pid) {
		/* Yes, just increment the number of references that I have */

		stream->fs_counts++;
	} else {
		/* Take the semaphore (perhaps waiting) */

		while (sem_wait(&stream->fs_sem) != 0) {
			/* The only case that an error should occr here is if the wait
			 * was awakened by a signal.
			 */

			ASSERT(get_errno() == EINTR);
		}

		/* We have it.  Claim the stak and return */

		stream->fs_holder = my_pid;
		stream->fs_counts = 1;
	}
}

/************************************************************************
 * lib_give_semaphore
 ************************************************************************/

void lib_give_semaphore(FAR struct file_struct *stream)
{
	pid_t my_pid = getpid();

	/* I better be holding at least one reference to the semaphore */

	ASSERT(stream->fs_holder == my_pid);

	/* Do I hold multiple references to the semphore */

	if (stream->fs_counts > 1) {
		/* Yes, just release one count and return */

		stream->fs_counts--;
	} else {
		/* Nope, this is the last reference I have */

		stream->fs_holder = -1;
		stream->fs_counts = 0;
		ASSERT(sem_post(&stream->fs_sem) == 0);
	}
}
#endif							/* CONFIG_STDIO_BUFFER_SIZE */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * libc/misc/lib_ioctl.c
 *
 *   Copyright (C) 2014 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <sys/ioctl.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#include <tinyara/fs/fs.h>

#include "lib_internal.h"

#if defined(CONFIG_LIBC_IOCTL_VARIADIC) && CONFIG_NFILE_DESCRIPTORS > 0

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: ioctl
 *
 * Description:
 *   Perform device specific operations.
 *
 * Parameters:
 *   fd       File/socket descriptor of device
 *   req      The ioctl command
 *   ...      A third argument of type unsigned long is expected
 *
 * Return:
 *   >=0 on success (positive non-zero values are cmd-specific)
 *   -1 on failure with errno set properly:
 *
 *   EBADF
 *     'fd' is not a valid descriptor.
 *   EFAULT
 *     'arg' references an inaccessible memory area.
 *   EINVAL
 *     'cmd' or 'arg' is not valid.
 *   ENOTTY
 *     'fd' is not associated with a character special device.
 *   ENOTTY
 *      The specified request does not apply to the kind of object that the
 *      descriptor 'fd' references.
 *
 ****************************************************************************/

int ioctl(int fd, int req, ...)
{
	unsigned long arg;
	va_list ap;

	/* Get the unsigned long argument.
	 *
	 * REVISIT:  This could be the cause of the crash down the road if the
	 * actual size of the argument is anything other than sizeof(unsigned long).
	 * Most small integers will be promoted to 'int'.  ARM should pass the
	 * following test with all three types having sizeof(type) == 4 bytes.
	 * 'float' should also be tested.  But 'long long' and 'double' are out of
	 * the question!  Don't try to pass them.
	 *
	 * And what will happen if no third argument is passed?  In most cases,
	 * this should just result in a garbage value for arg.  But you may
	 * discover cases where something worse happens!
	 */

	DEBUGASSERT(sizeof(int) == sizeof(unsigned long) && sizeof(FAR void *) == sizeof(unsigned long));

	va_start(ap, req);
	arg = va_arg(ap, unsigned long);
	va_end(ap);

	/* Then let fs_ioctl() to the real work */

	return fs_ioctl(fd, req, arg);
}

#endif							/* CONFIG_LIBC_IOCTL_VARIADIC && CONFIG_NFILE_DESCRIPTORS > 0 */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * libc/misc/lib_match.c - simple shell-style filename matcher
 *
 * Simple shell-style filename pattern matcher written by Jef Poskanzer
 * This pattern matcher only handles '?', '*' and '**', and  multiple
 * patterns separated by '|'.
 *
 *   Copyright © 1995, 2000 by Jef Poskanzer <jef@mail.acme.com>.
 *   All rights reserved.
 *
 * With extensions by Ken Pettit.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <string.h>
#include <tinyara/regex.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: match_one
 *
 * Description:
 *   Does all of the work for one '|' delimited pattern
 *
 * Returned Value:
 *   Returns 1 (match) or 0 (no-match).
 *
 ****************************************************************************/

static int match_one(const char *pattern, int patlen, const char *string)
{
	const char *p;
	char first;
	int pl;
	int i;

	for (p = pattern; p - pattern < patlen; p++, string++) {
		if (*p == '?' && *string != '\0') {
			continue;
		}

		/* Match single character from a set:  "[a-zA-Z]" for instance */

		if (*p == '[' && *string != '\0') {
			i = 0;
			while (*p != ']' && *p != '\0') {
				p++;

				if (*string == *p) {
					/* Match found.  Advance to the ']' */

					i = 1;
					while (*p != ']' && *p != '\0') {
						p++;
					}

					break;
				}

				/* Prepare to test for range */

				if (*p != '\0') {
					first = *p++;
					if (*p == '-') {
						p++;
						if (*string >= first && *string <= *p) {
							/* Match found.  Advance to the ']' */

							i = 1;
							while (*p != ']' && *p != '\0') {
								p++;
							}

							break;
						}
					}
				}
			}

			/* We reuse 'i' above to indicate match found */

			if (i) {
				continue;
			}

			return 0;
		}

		if (*p == '*') {
			p++;
			if (*p == '*') {
				/* Double-wildcard matches anything. */

				p++;
				i = strlen(string);
			} else {
				/* Single-wildcard matches anything but slash. */

				i = strcspn(string, "/");
			}

			pl = patlen - (p - pattern);
			for (; i >= 0; i--) {
				if (match_one(p, pl, &(string[i]))) {
					return 1;
				}
			}

			return 0;
		}

		if (*p != *string) {
			return 0;
		}
	}

	if (*string == '\0') {
		return 1;
	}

	return 0;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: match
 *
 * Description:
 *   Simple shell-style filename pattern matcher originally written by
 *   Jef Poskanzer and extended by Ken Pettit.  This pattern matcher handles
 *   '?', '*', '**', sets like [a-zA-z], and multiple  patterns separated
 *   by '|'.
 *
 * Returned Value:
 *   Returns 1 (match) or 0 (no-match).
 *
 ****************************************************************************/

int match(const char *pattern, const char *string)
{
	const char *or;

	for (;;) {
		or = strchr(pattern, '|');
		if (or == (char *)0) {
			return match_one(pattern, strlen(pattern), string);
		}

		if (match_one(pattern, or - pattern, string)) {
			return 1;
		}

		pattern = or + 1;
	}
}
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/************************************************************************
 * libc/misc/lib_sendfile.c
 *
 *   Copyright (C) 2007, 2009, 2011, 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <sys/sendfile.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "lib_internal.h"

#if CONFIG_NSOCKET_DESCRIPTORS > 0 || CONFIG_NFILE_DESCRIPTORS > 0

/************************************************************************
 * Private types
 ************************************************************************/

/************************************************************************
 * Private Variables
 ************************************************************************/

/************************************************************************
 * Public Variables
 ************************************************************************/

/************************************************************************
 * Private Functions
 ************************************************************************/

/************************************************************************
 * Public Functions
 ************************************************************************/

/************************************************************************
 * Name: sendfile / lib_sendfile
 *
 * Description:
 *   sendfile() copies data between one file descriptor and another.
 *   sendfile() basically just wraps a sequence of reads() and writes()
 *   to perform a copy.  It serves a purpose in systems where there is
 *   a penalty for copies to between user and kernal space, but really
 *   nothing in TinyAra but provide some Linux compatible (and adding
 *   another 'almost standard' interface).
 *
 *   NOTE: This interface is *not* specified in POSIX.1-2001, or other
 *   standards.  The implementation here is very similar to the Linux
 *   sendfile interface.  Other UNIX systems implement sendfile() with
 *   different semantics and prototypes.  sendfile() should not be used
 *   in portable programs.
 *
 * Input Parmeters:
 *   infd   - A file (or socket) descriptor opened for reading
 *   outfd  - A descriptor opened for writing.
 *   offset - If 'offset' is not NULL, then it points to a variable
 *            holding the file offset from which sendfile() will start
 *            reading data from 'infd'.  When sendfile() returns, this
 *            variable will be set to the offset of the byte following
 *            the last byte that was read.  If 'offset' is not NULL,
 *            then sendfile() does not modify the current file offset of
 *            'infd'; otherwise the current file offset is adjusted to
 *            reflect the number of bytes read from 'infd.'
 *
 *            If 'offset' is NULL, then data will be read from 'infd'
 *            starting at the current file offset, and the file offset
 *            will be updated by the call.
 *   count -  The number of bytes to copy between the file descriptors.
 *
 * Returned Value:
 *   If the transfer was successful, the number of bytes written to outfd is
 *   returned.  On error, -1 is returned, and errno is set appropriately.
 *   There error values are those returned by read() or write() plus:
 *
 *   EINVAL - Bad input parameters.
 *   ENOMEM - Could not allocated an I/O buffer
 *
 ************************************************************************/

ssize_t sendfile(int outfd, int infd, off_t *offset, size_t count)
{
	FAR uint8_t *iobuffer;
	FAR uint8_t *wrbuffer;
	off_t startpos = 0;
	ssize_t nbytesread;
	ssize_t nbyteswritten;
	ssize_t ntransferred;
	bool endxfr;

	/* Get the current file position. */

	if (offset) {
		/* Use lseek to get the current file position */

		startpos = lseek(infd, 0, SEEK_CUR);
		if (startpos == (off_t)-1) {
			return ERROR;
		}

		/* Use lseek again to set the new file position */

		if (lseek(infd, *offset, SEEK_SET) == (off_t)-1) {
			return ERROR;
		}
	}

	/* Allocate an I/O buffer */

	iobuffer = (FAR void *)lib_malloc(CONFIG_LIB_SENDFILE_BUFSIZE);
	if (!iobuffer) {
		set_errno(ENOMEM);
		return ERROR;
	}

	/* Now transfer 'count' bytes from the infd to the outfd */

	for (ntransferred = 0, endxfr = false; ntransferred < count && !endxfr;) {
		/* Loop until the read side of the transfer comes to some conclusion */

		do {
			/* Read a buffer of data from the infd */

			nbytesread = read(infd, iobuffer, CONFIG_LIB_SENDFILE_BUFSIZE);

			/* Check for end of file */

			if (nbytesread == 0) {
				/* End of file.  Break out and return current number of bytes
				 * transferred.
				 */

				endxfr = true;
				break;
			}

			/* Check for a read ERROR.  EINTR is a special case.  This function
			 * should break out and return an error if EINTR is returned and
			 * no data has been transferred.  But what should it do if some
			 * data has been transferred?  I suppose just continue?
			 */

			else if (nbytesread < 0) {
				/* EINTR is not an error (but will still stop the copy) */

#ifndef CONFIG_DISABLE_SIGNALS
				if (errno != EINTR || ntransferred == 0)
#endif
				{
					/* Read error.  Break out and return the error condition. */

					ntransferred = ERROR;
					endxfr = true;
					break;
				}
			}
		} while (nbytesread < 0);

		/* Was anything read? */

		if (!endxfr) {
			/* Yes.. Loop until the read side of the transfer comes to some
			 * conclusion.
			 */

			wrbuffer = iobuffer;
			do {
				/* Write the buffer of data to the outfd */

				nbyteswritten = write(outfd, wrbuffer, nbytesread);

				/* Check for a complete (or parial) write.  write() should not
				 * return zero.
				 */

				if (nbyteswritten >= 0) {
					/* Advance the buffer pointer and decrement the number of bytes
					 * remaining in the iobuffer.  Typically, nbytesread will now
					 * be zero.
					 */

					wrbuffer += nbyteswritten;
					nbytesread -= nbyteswritten;

					/* Increment the total number of bytes successfully transferred. */

					ntransferred += nbyteswritten;
				}

				/* Otherwise an error occurred */

				else {
					/* Check for a read ERROR.  EINTR is a special case.  This
					 * function should break out and return an error if EINTR
					 * is returned and no data has been transferred.  But what
					 * should it do if some data has been transferred?  I
					 * suppose just continue?
					 */

#ifndef CONFIG_DISABLE_SIGNALS
					if (errno != EINTR || ntransferred == 0)
#endif
					{
						/* Write error.  Break out and return the error condition */

						ntransferred = ERROR;
						endxfr = true;
						break;
					}
				}
			} while (nbytesread > 0);
		}
	}

	/* Release the I/O buffer */

	lib_free(iobuffer);

	/* Return the current file position */

	if (offset) {
		/* Use lseek to get the current file position */

		off_t curpos = lseek(infd, 0, SEEK_CUR);
		if (curpos == (off_t)-1) {
			return ERROR;
		}

		/* Return the current file position */

		*offset = curpos;

		/* Use lseek again to restore the original file position */

		if (lseek(infd, startpos, SEEK_SET) == (off_t)-1) {
			return ERROR;
		}
	}

	/* Finally return the number of bytes actually transferred (or ERROR
	 * if any failure occurred).
	 */

	return ntransferred;
}

#endif							/* CONFIG_NSOCKET_DESCRIPTORS > 0 || CONFIG_NFILE_DESCRIPTORS > 0 */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/****************************************************************************
 * libc/misc/lib_stream.c
 *
 *   Copyright (C) 2007, 2011, 2013-2014 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <tinyara/config.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <tinyara/kmalloc.h>
#include <tinyara/sched.h>
#include <tinyara/fs/fs.h>
#include <tinyara/lib.h>

#include "lib_internal.h"

#if (!defined(CONFIG_BUILD_PROTECTED) && !defined(CONFIG_BUILD_KERNEL)) || \
	  defined(__KERNEL__)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Variables
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_stream_initialize
 *
 * Description:
 *   This function is called when a new task is allocated.  It initializes
 *   the streamlist instance that is stored in the task group.
 *
 ****************************************************************************/

#if CONFIG_NFILE_STREAMS > 0
void lib_stream_initialize(FAR struct task_group_s *group)
{
	FAR struct streamlist *list;
	int i;

#if (defined(CONFIG_BUILD_PROTECTED) || defined(CONFIG_BUILD_KERNEL)) && \
	 defined(CONFIG_MM_KERNEL_HEAP)
	DEBUGASSERT(group && group->tg_streamlist);
	list = group->tg_streamlist;
#else
	DEBUGASSERT(group);
	list = &group->tg_streamlist;
#endif

	/* Initialize the list access mutex */

	(void)sem_init(&list->sl_sem, 0, 1);

	/* Initialize each FILE structure */

	for (i = 0; i < CONFIG_NFILE_STREAMS; i++) {

		FAR struct file_struct *stream = &list->sl_streams[i];

		/* Clear the IOB */

		memset(stream, 0, sizeof(FILE));

		/* Indicate not opened */

		stream->fs_fd = -1;

		/* Initialize the stream semaphore to one to support one-at-
		 * a-time access to private data sets.
		 */

		lib_sem_initialize(&list->sl_streams[i]);
	}
}
#endif							/* CONFIG_NFILE_STREAMS > 0 */

/****************************************************************************
 * Name: lib_stream_init
 *
 * Description:
 *   This function is called when a TCB is destroyed.  Note that it does not
 *   close the files by releasing the inode.  That happens separately when
 *   the file descriptor list is freed.
 *
 ****************************************************************************/

#if CONFIG_NFILE_STREAMS > 0
void lib_stream_release(FAR struct task_group_s *group)
{
	FAR struct streamlist *list;
#if CONFIG_STDIO_BUFFER_SIZE > 0
	int i;
#endif

#if (defined(CONFIG_BUILD_PROTECTED) || defined(CONFIG_BUILD_KERNEL)) && \
	 defined(CONFIG_MM_KERNEL_HEAP)
	DEBUGASSERT(group && group->tg_streamlist);
	list = group->tg_streamlist;
#else
	DEBUGASSERT(group);
	list = &group->tg_streamlist;
#endif

	/* Destroy the semaphore and release the filelist */

	(void)sem_destroy(&list->sl_sem);

	/* Release each stream in the list */

#if CONFIG_STDIO_BUFFER_SIZE > 0
	for (i = 0; i < CONFIG_NFILE_STREAMS; i++) {

		FAR struct file_struct *stream = &list->sl_streams[i];

		/* Destroy the semaphore that protects the IO buffer */

		(void)sem_destroy(&stream->fs_sem);

		/* Release the IO buffer */

		if (stream->fs_bufstart != NULL && (stream->fs_flags & __FS_FLAG_UBF) == 0) {
#ifndef CONFIG_BUILD_KERNEL
			/* Release memory from the user heap */

			sched_ufree(stream->fs_bufstart);
#else
			/* If the exiting group is unprivileged, then it has an address
			 * environment.  Don't bother to release the memory in this case...
			 * There is no point since the memory lies in the user heap which
			 * will be destroyed anyway.  But if this is a privileged group,
			 * when we still have to release the memory using the kernel
			 * allocator.
			 */

			if ((group->tg_flags & GROUP_FLAG_PRIVILEGED) != 0) {
				sched_kfree(stream->fs_bufstart);
			}
#endif
		}
	}
#endif
}
#endif							/* CONFIG_NFILE_STREAMS > 0 */

#endif							/* (!CONFIG_BUILD_PROTECTED &&7 !CONFIG_BUILD_KERNEL) || __KERNEL__ */
/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 * EDIT: Georgi Angelov 2018
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
/************************************************************************
 * libc/misc/lib_streamsem.c
 *
 *   Copyright (C) 2007, 2009, 2011 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************/

/************************************************************************
 * Included Files
 ************************************************************************/

#include <tinyara/config.h>

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <semaphore.h>
#include <errno.h>
#include <tinyara/fs/fs.h>

#include "lib_internal.h"

/************************************************************************
 * Private types
 ************************************************************************/

/************************************************************************
 * Private Variables
 ************************************************************************/

/************************************************************************
 * Public Variables
 ************************************************************************/

/************************************************************************
 * Private Functions
 ************************************************************************/

/************************************************************************
 * Public Functions
 ************************************************************************/

void stream_semtake(FAR struct streamlist *list)
{
	/* Take the semaphore (perhaps waiting) */

	while (sem_wait(&list->sl_sem) != 0) {
		/* The only case that an error should occr here is if
		 * the wait was awakened by a signal.
		 */

		ASSERT(get_errno() == EINTR);
	}
}

void stream_semgive(FAR struct streamlist *list)
{
	sem_post(&list->sl_sem);
}
   