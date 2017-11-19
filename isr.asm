;********************************************************************************
;     isr.asm
;     0.0.3
;     Copyright (C) 2006  Kenneth Perry Hough
; 
;     This program is free software; you can redistribute it and/or modify
;     it under the terms of the GNU General Public License as published by
;     the Free Software Foundation; either version 2 of the License, or
;     (at your option) any later version.
; 
;     This program is distributed in the hope that it will be useful,
;     but WITHOUT ANY WARRANTY; without even the implied warranty of
;     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;     GNU General Public License for more details.
; 
;     You should have received a copy of the GNU General Public License along
;     with this program; if not, write to the Free Software Foundation, Inc.,
;     51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
; 
;     e-mail:
;     kennethphough@gmail.com
;********************************************************************************

[BITS 32]

global isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7, isr8, isr9, isr10, isr11, isr12, isr13, isr14, isr15, isr16, isr17, isr18, isr19, isr20, isr21, isr22, isr23, isr24, isr25, isr26, isr27, isr28, isr29, isr30, isr31, irq0, irq1, irq2, irq3, irq4, irq5, irq6, irq7, irq8, irq9, irq10, irq11, irq12, irq13, irq14, irq15
extern excp_hndlr_0, excp_hndlr_1, excp_hndlr_2, excp_hndlr_3, excp_hndlr_4, excp_hndlr_5, excp_hndlr_6, excp_hndlr_7, excp_hndlr_8, excp_hndlr_9, excp_hndlr_10, excp_hndlr_11, excp_hndlr_12, excp_hndlr_13, excp_hndlr_14, excp_hndlr_15, excp_hndlr_16, excp_hndlr_17, excp_hndlr_18, excp_hndlr_19, excp_hndlr_20, excp_hndlr_21, excp_hndlr_22, excp_hndlr_23, excp_hndlr_24, excp_hndlr_25, excp_hndlr_26, excp_hndlr_27, excp_hndlr_28, excp_hndlr_29, excp_hndlr_30, excp_hndlr_31, irq_hndlr_0, irq_hndlr_1, irq_hndlr_2, irq_hndlr_3, irq_hndlr_4, irq_hndlr_5, irq_hndlr_6, irq_hndlr_7, irq_hndlr_8, irq_hndlr_9, irq_hndlr_10, irq_hndlr_11, irq_hndlr_12, irq_hndlr_13, irq_hndlr_14, irq_hndlr_15

global load_idt
extern idtp

load_idt:
lidt[idtp]
ret

;;Exceptions 0 - 31
isr0:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_0

pop ds
pop es
pop fs
pop gs
popa
iret

isr1:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_1

pop ds
pop es
pop fs
pop gs
popa
iret

isr2:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_2

pop ds
pop es
pop fs
pop gs
popa
iret

isr3:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_3

pop ds
pop es
pop fs
pop gs
popa
iret

isr4:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_4

pop ds
pop es
pop fs
pop gs
popa
iret

isr5:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_5

pop ds
pop es
pop fs
pop gs
popa
iret

isr6:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_6

pop ds
pop es
pop fs
pop gs
popa
iret

isr7:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_7

pop ds
pop es
pop fs
pop gs
popa
iret

isr8:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_8

pop ds
pop es
pop fs
pop gs
popa
iret

isr9:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_9

pop ds
pop es
pop fs
pop gs
popa
iret

isr10:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_10

pop ds
pop es
pop fs
pop gs
popa
iret

isr11:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_11

pop ds
pop es
pop fs
pop gs
popa
iret

isr12:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_12

pop ds
pop es
pop fs
pop gs
popa
iret

isr13:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_13

pop ds
pop es
pop fs
pop gs
popa
iret

isr14:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_14

pop ds
pop es
pop fs
pop gs
popa
iret

isr15:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_15

pop ds
pop es
pop fs
pop gs
popa
iret

isr16:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_16

pop ds
pop es
pop fs
pop gs
popa
iret

isr17:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_17

pop ds
pop es
pop fs
pop gs
popa
iret

isr18:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_18

pop ds
pop es
pop fs
pop gs
popa
iret

isr19:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_19

pop ds
pop es
pop fs
pop gs
popa
iret

isr20:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_20

pop ds
pop es
pop fs
pop gs
popa
iret

isr21:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_21

pop ds
pop es
pop fs
pop gs
popa
iret

isr22:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_22

pop ds
pop es
pop fs
pop gs
popa
iret

isr23:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_23

pop ds
pop es
pop fs
pop gs
popa
iret

isr24:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_24

pop ds
pop es
pop fs
pop gs
popa
iret

isr25:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_25

pop ds
pop es
pop fs
pop gs
popa
iret

isr26:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_26

pop ds
pop es
pop fs
pop gs
popa
iret

isr27:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_27

pop ds
pop es
pop fs
pop gs
popa
iret

isr28:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_28

pop ds
pop es
pop fs
pop gs
popa
iret

isr29:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_29

pop ds
pop es
pop fs
pop gs
popa
iret

isr30:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_30

pop ds
pop es
pop fs
pop gs
popa
iret

isr31:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call excp_hndlr_31

pop ds
pop es
pop fs
pop gs
popa
iret

;;IRQ 0 - 15
irq0:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_0

pop ds
pop es
pop fs
pop gs
popa
iret

irq1:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_1

pop ds
pop es
pop fs
pop gs
popa
iret

irq2:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_2

pop ds
pop es
pop fs
pop gs
popa
iret

irq3:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_3

pop ds
pop es
pop fs
pop gs
popa
iret

irq4:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_4

pop ds
pop es
pop fs
pop gs
popa
iret

irq5:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_5

pop ds
pop es
pop fs
pop gs
popa
iret

irq6:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_6

pop ds
pop es
pop fs
pop gs
popa
iret

irq7:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_7

pop ds
pop es
pop fs
pop gs
popa
iret

irq8:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_8

pop ds
pop es
pop fs
pop gs
popa
iret

irq9:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_9

pop ds
pop es
pop fs
pop gs
popa
iret

irq10:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_10

pop ds
pop es
pop fs
pop gs
popa
iret

irq11:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_11

pop ds
pop es
pop fs
pop gs
popa
iret

irq12:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_12

pop ds
pop es
pop fs
pop gs
popa
iret

irq13:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_13

pop ds
pop es
pop fs
pop gs
popa
iret

irq14:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_14

pop ds
pop es
pop fs
pop gs
popa
iret

irq15:
cli

pusha
push gs
push fs
push es
push ds

mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call irq_hndlr_15

pop ds
pop es
pop fs
pop gs
popa
iret
