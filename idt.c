/********************************************************************************
    idt.c
    0.0.2
    Copyright (C) 2006  Kenneth Perry Hough

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    e-mail:
    kennethphough@gmail.com
********************************************************************************/

#include <asm.h>
#include <datatypes.h>

//IDT entry structure
struct idt_entry
{
	WORD base_low;
	WORD selector;
	BYTE param_count;
	BYTE type;
	WORD base_high;
} __attribute__((packed));

//IDT descriptor
struct idt_ptr
{
	WORD limit;
	DWORD base;
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr idtp;

//create new entry for IDT
void new_idt(unsigned char id, unsigned int base, unsigned short selector, unsigned char type) {

	idt[id].base_low = (base & 0xFFFF);
	idt[id].base_high = ((base >> 16) & 0xFFFF);

	idt[id].selector = selector;
	idt[id].param_count = 0;
	idt[id].type = type;
}

//initialize IDT
void idt_init(void) {
	idtp.limit = (sizeof(struct idt_ptr)*256)-1;
	idtp.base = &idt;

	int i;

	//Set all 256 IDT entries to 0
	for(i=0;i<256;i++) {
		idt[i].base_low = 0;
		idt[i].selector = 0;
		idt[i].param_count = 0;
		idt[i].type = 0;
		idt[i].base_high = 0;
	}

	//Set IDT entries for exceptions 0 - 31
	new_idt(0, (unsigned)isr0, 0x08, 0x8E);
	new_idt(1, (unsigned)isr1, 0x08, 0x8E);
	new_idt(2, (unsigned)isr2, 0x08, 0x8E);
	new_idt(3, (unsigned)isr3, 0x08, 0x8E);
	new_idt(4, (unsigned)isr4, 0x08, 0x8E);
	new_idt(5, (unsigned)isr5, 0x08, 0x8E);
	new_idt(6, (unsigned)isr6, 0x08, 0x8E);
	new_idt(7, (unsigned)isr7, 0x08, 0x8E);
	new_idt(8, (unsigned)isr8, 0x08, 0x8E);
	new_idt(9, (unsigned)isr9, 0x08, 0x8E);
	new_idt(10, (unsigned)isr10, 0x08, 0x8E);
	new_idt(11, (unsigned)isr11, 0x08, 0x8E);
	new_idt(12, (unsigned)isr12, 0x08, 0x8E);
	new_idt(13, (unsigned)isr13, 0x08, 0x8E);
	new_idt(14, (unsigned)isr14, 0x08, 0x8E);
	new_idt(15, (unsigned)isr15, 0x08, 0x8E);
	new_idt(16, (unsigned)isr16, 0x08, 0x8E);
	new_idt(17, (unsigned)isr17, 0x08, 0x8E);
	new_idt(18, (unsigned)isr18, 0x08, 0x8E);
	new_idt(19, (unsigned)isr19, 0x08, 0x8E);
	new_idt(20, (unsigned)isr20, 0x08, 0x8E);
	new_idt(21, (unsigned)isr21, 0x08, 0x8E);
	new_idt(22, (unsigned)isr22, 0x08, 0x8E);
	new_idt(23, (unsigned)isr23, 0x08, 0x8E);
	new_idt(24, (unsigned)isr24, 0x08, 0x8E);
	new_idt(25, (unsigned)isr25, 0x08, 0x8E);
	new_idt(26, (unsigned)isr26, 0x08, 0x8E);
	new_idt(27, (unsigned)isr27, 0x08, 0x8E);
	new_idt(28, (unsigned)isr28, 0x08, 0x8E);
	new_idt(29, (unsigned)isr29, 0x08, 0x8E);
	new_idt(30, (unsigned)isr30, 0x08, 0x8E);
	new_idt(31, (unsigned)isr31, 0x08, 0x8E);

	load_idt();
}
