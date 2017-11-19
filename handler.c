/********************************************************************************
    handler.c
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

#include <video.h>
#include <io.h>
#include <keyboard.h>
#include <timer.h>

//EXCEPTION HANDLER

void excp_hndlr_0(void) {
	sysprint("EXCEPTION 0\n#DE\nDivide Error\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_1(void) {
	sysprint("EXCEPTION 1\n#DB\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_2(void) {
	sysprint("EXCEPTION 2\nN/A\nNMI Interrupt\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_3(void) {
	sysprint("EXCEPTION 3\n#BP\nBreakpoint\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_4(void) {
	sysprint("EXCEPTION 4\n#OF\nOverflow\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_5(void) {
	sysprint("EXCEPTION 5\n#BR\nBOUND Range Exceeded\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_6(void) {
	sysprint("EXCEPTION 6\n#UD\nInvalid Opcode (Undefined Opcode)\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_7(void) {
	sysprint("EXCEPTION 7\n#NM\nDevice Not Available (No Math Coprocessor)\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_8(void) {
	sysprint("EXCEPTION 8\n#DF\nDouble Fault\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_9(void) {
	sysprint("EXCEPTION 9\nN/A\nCoprocessor Segment Overrun (reserved)\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_10(void) {
	sysprint("EXCEPTION 10\n#TS\nInvalid TSS\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_11(void) {
	sysprint("EXCEPTION 11\n#NP\nSegment Not Present\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_12(void) {
	sysprint("EXCEPTION 12\n#SS\nStack-Segment Fault\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_13(void) {
	sysprint("EXCEPTION 13\n#GP\nGeneral Protection\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_14(void) {
	sysprint("EXCEPTION 14\n#PF\nPage Fault\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_15(void) {
	sysprint("EXCEPTION 15\n#N/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_16(void) {
	sysprint("EXCEPTION 16\n#MF\nx87 FPU Floating-Point Error (Math Fault)\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_17(void) {
	sysprint("EXCEPTION 17\n#AC\nAlignment Check\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_18(void) {
	sysprint("EXCEPTION 18\n#MC\nMachine Check\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_19(void) {
	sysprint("EXCEPTION 19\n#XF\nSIMD Floating-Point Exception\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_20(void) {
	sysprint("EXCEPTION 20\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_21(void) {
	sysprint("EXCEPTION 21\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_22(void) {
	sysprint("EXCEPTION 22\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_23(void) {
	sysprint("EXCEPTION 23\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}
void excp_hndlr_24(void) {
	sysprint("EXCEPTION 24\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_25(void) {
	sysprint("EXCEPTION 25\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_26(void) {
	sysprint("EXCEPTION 26\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_27(void) {
	sysprint("EXCEPTION 27\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_28(void) {
	sysprint("EXCEPTION 28\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_29(void) {
	sysprint("EXCEPTION 29\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_30(void) {
	sysprint("EXCEPTION 30\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}

void excp_hndlr_31(void) {
	sysprint("EXCEPTION 31\nN/A\nRESERVED\nSYSTEM HALTED\n");
	for(;;);
}


//IRQ HANDLER

//Timer
void irq_hndlr_0(void) {
	timer_hndlr();
	outportb(0x20, 0x20);
}

//Keyboard
void irq_hndlr_1(void) {
	keyboard_hndlr();
	outportb(0x20, 0x20);
}

void irq_hndlr_2(void) {
	sysprint("IRQ 2\nN/A\nHDR_INT\n");
	outportb(0x20, 0x20);
}

void irq_hndlr_3(void) {
	sysprint("IRQ 3\nN/A\nHDR_INT\n");
	outportb(0x20, 0x20);
}

void irq_hndlr_4(void) {
	sysprint("IRQ 4\nN/A\nHDR_INT\n");
	outportb(0x20, 0x20);
}

void irq_hndlr_5(void) {
	sysprint("IRQ 5\nN/A\nHDR_INT\n");
	outportb(0x20, 0x20);
}

void irq_hndlr_6(void) {
	sysprint("IRQ 6\nN/A\nHDR_INT\n");
	outportb(0x20, 0x20);
}

void irq_hndlr_7(void) {
	sysprint("IRQ 7\nN/A\nHDR_INT\n");
	outportb(0x20, 0x20);
}

void irq_hndlr_8(void) {
	sysprint("IRQ 8\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_9(void) {
	sysprint("IRQ 9\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_10(void) {
	sysprint("IRQ 10\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_11(void) {
	sysprint("IRQ 11\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_12(void) {
	sysprint("IRQ 12\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_13(void) {
	sysprint("IRQ 13\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_14(void) {
	sysprint("IRQ 14\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}

void irq_hndlr_15(void) {
	sysprint("IRQ 15\nN/A\nHDR_INT\n");
	outportb(0xA0, 0x20);
	outportb(0x20, 0x20);
}
