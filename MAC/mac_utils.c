/*********************************************************************************

MIT License

Copyright (c) 2016 Microsoft

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


// Invert bits in everyt byte of arr using a precomputed LUT
void invert_bits(unsigned char * arr, int len) {
	unsigned char LUT[256] = { 0x000, 0x080, 0x040, 0x0c0, 0x020, 0x0a0, 0x060, 0x0e0, 0x010, 0x090, 0x050, 0x0d0, 0x030, 0x0b0, 0x070, 0x0f0, 
							   0x008, 0x088, 0x048, 0x0c8, 0x028, 0x0a8, 0x068, 0x0e8, 0x018, 0x098, 0x058, 0x0d8, 0x038, 0x0b8, 0x078, 0x0f8, 
							   0x004, 0x084, 0x044, 0x0c4, 0x024, 0x0a4, 0x064, 0x0e4, 0x014, 0x094, 0x054, 0x0d4, 0x034, 0x0b4, 0x074, 0x0f4,
							   0x00c, 0x08c, 0x04c, 0x0cc, 0x02c, 0x0ac, 0x06c, 0x0ec, 0x01c, 0x09c, 0x05c, 0x0dc, 0x03c, 0x0bc, 0x07c, 0x0fc,
							   0x002, 0x082, 0x042, 0x0c2, 0x022, 0x0a2, 0x062, 0x0e2, 0x012, 0x092, 0x052, 0x0d2, 0x032, 0x0b2, 0x072, 0x0f2,
							   0x00a, 0x08a, 0x04a, 0x0ca, 0x02a, 0x0aa, 0x06a, 0x0ea, 0x01a, 0x09a, 0x05a, 0x0da, 0x03a, 0x0ba, 0x07a, 0x0fa,
							   0x006, 0x086, 0x046, 0x0c6, 0x026, 0x0a6, 0x066, 0x0e6, 0x016, 0x096, 0x056, 0x0d6, 0x036, 0x0b6, 0x076, 0x0f6,
							   0x00e, 0x08e, 0x04e, 0x0ce, 0x02e, 0x0ae, 0x06e, 0x0ee, 0x01e, 0x09e, 0x05e, 0x0de, 0x03e, 0x0be, 0x07e, 0x0fe,
							   0x001, 0x081, 0x041, 0x0c1, 0x021, 0x0a1, 0x061, 0x0e1, 0x011, 0x091, 0x051, 0x0d1, 0x031, 0x0b1, 0x071, 0x0f1,
							   0x009, 0x089, 0x049, 0x0c9, 0x029, 0x0a9, 0x069, 0x0e9, 0x019, 0x099, 0x059, 0x0d9, 0x039, 0x0b9, 0x079, 0x0f9,
							   0x005, 0x085, 0x045, 0x0c5, 0x025, 0x0a5, 0x065, 0x0e5, 0x015, 0x095, 0x055, 0x0d5, 0x035, 0x0b5, 0x075, 0x0f5,
							   0x00d, 0x08d, 0x04d, 0x0cd, 0x02d, 0x0ad, 0x06d, 0x0ed, 0x01d, 0x09d, 0x05d, 0x0dd, 0x03d, 0x0bd, 0x07d, 0x0fd,
							   0x003, 0x083, 0x043, 0x0c3, 0x023, 0x0a3, 0x063, 0x0e3, 0x013, 0x093, 0x053, 0x0d3, 0x033, 0x0b3, 0x073, 0x0f3,
							   0x00b, 0x08b, 0x04b, 0x0cb, 0x02b, 0x0ab, 0x06b, 0x0eb, 0x01b, 0x09b, 0x05b, 0x0db, 0x03b, 0x0bb, 0x07b, 0x0fb,
							   0x007, 0x087, 0x047, 0x0c7, 0x027, 0x0a7, 0x067, 0x0e7, 0x017, 0x097, 0x057, 0x0d7, 0x037, 0x0b7, 0x077, 0x0f7,
							   0x00f, 0x08f, 0x04f, 0x0cf, 0x02f, 0x0af, 0x06f, 0x0ef, 0x01f, 0x09f, 0x05f, 0x0df, 0x03f, 0x0bf, 0x07f, 0x0ff };

	for (int i = 0; i < len; i++)
	{
		arr[i] = LUT[arr[i]];
	}
}


void* inmem_malloc(size_t size)
{
	void *ptr = malloc(size);
	if (ptr == NULL)
	{
		printf("inmem_malloc failed!\n");
		exit(1);
	}
	VirtualLock(ptr, size);
	return ptr;
}
