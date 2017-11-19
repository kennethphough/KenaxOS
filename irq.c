/********************************************************************************
    irq.c
    0.0.1
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
#include <io.h>
#include <idt.h>

//remap IRQs in PIC
void remap_irq(void) {
	outportb(0x20, 0x11);
	outportb(0xA0, 0x11);
	outportb(0x21, 0x20);
	outportb(0xA1, 0x28);
	outportb(0x21, 0x04);
	outportb(0xA1, 0x02);
	outportb(0x21, 0x01);
	outportb(0xA1, 0x01);
	outportb(0x21, 0x0);
	outportb(0xA1, 0x0);
}

//initialize IRQ
void irq_init(void) {
	remap_irq();

	new_idt(32, (unsigned)irq0, 0x08, 0x8E);
	new_idt(33, (unsigned)irq1, 0x08, 0x8E);
	new_idt(34, (unsigned)irq2, 0x08, 0x8E);
	new_idt(25, (unsigned)irq3, 0x08, 0x8E);
	new_idt(36, (unsigned)irq4, 0x08, 0x8E);
	new_idt(37, (unsigned)irq5, 0x08, 0x8E);
	new_idt(38, (unsigned)irq6, 0x08, 0x8E);
	new_idt(39, (unsigned)irq7, 0x08, 0x8E);

	new_idt(40, (unsigned)irq8, 0x08, 0x8E);
	new_idt(41, (unsigned)irq9, 0x08, 0x8E);
	new_idt(42, (unsigned)irq10, 0x08, 0x8E);
	new_idt(43, (unsigned)irq11, 0x08, 0x8E);
	new_idt(44, (unsigned)irq12, 0x08, 0x8E);
	new_idt(45, (unsigned)irq13, 0x08, 0x8E);
	new_idt(46, (unsigned)irq14, 0x08, 0x8E);
	new_idt(47, (unsigned)irq15, 0x08, 0x8E);
}
