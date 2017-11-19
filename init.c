/********************************************************************************
    init.c
    0.0.3
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
#include <video.h>
#include <idt.h>
#include <irq.h>
#include <keyboard.h>

void init(void) {
	gdt_flush();  //set up new GDT
	idt_init();  //create an IDT
	irq_init();  //remap PIC, and set up IRQ handlers
	timer_init();  //change timer settings to 100HZ
	keyboard_init();
	vid_init();  //initialize screen
}
