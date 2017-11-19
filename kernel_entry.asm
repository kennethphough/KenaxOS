;********************************************************************************
;     kernel_entry.asm
;     0.0.4
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
global start
start:
    mov esp, _sys_stack
    jmp stublet

ALIGN 4
mboot:
    MULTIBOOT_PAGE_ALIGN        equ 1<<0
    MULTIBOOT_MEMORY_INFO       equ 1<<1
    MULTIBOOT_AOUT_KLUDGE       equ 1<<16
    MULTIBOOT_HEADER_MAGIC      equ 0x1BADB002
    MULTIBOOT_HEADER_FLAGS      equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
    MULTIBOOT_CHECKSUM  equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
    EXTERN code, bss, end

    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_FLAGS
    dd MULTIBOOT_CHECKSUM
    
    dd mboot
    dd code
    dd bss
    dd end
    dd start

stublet:
    extern main
    call main
    jmp $

global sys_sti, sys_cli

;;Set Interrupts - void sys_sti(void);
sys_sti:
sti
ret

;;Clear Interrupts - void sys_cli(void);
sys_cli:
cli
ret

global cr0_read, cr0_write

;;Read CR0 - int cr0_read(void);
cr0_read:
xor eax, eax  ;;eax = 0
mov eax, cr0  ;;eax = cr0
ret

;;Write to CR0 - void cr0_write(int data);
cr0_write:
push ebp  ;;we want to use ebp to, so we first save the content of ebp
xor eax, eax  ;;eax = 0
mov ebp, esp  ;;ebp = esp
mov eax, [ebp+8]  ;;eax = data
mov cr0, eax  ;;cr0 = eax
pop ebp  ;;restore the content of ebp
ret

global read_EFLAGS, write_EFLAGS

;;Read EFLAGS - int EFLAGS_read(void);
EFLAGS_read:
xor eax, eax  ;;eax = 0
pushfd  ;;push the content of the EFLAGS on stack
pop eax  ;;pop the content of the EFLAGS from stack to the eax register
ret

;;Write to EFLAGS - void EFLAGS_write(int eflags);
EFLAGS_write:
xor eax, eax  ;;eax = 0
mov eax, [esp+4]  ;;eax = eflags
push eax  ;;push the content of eflags on stack
popfd  ;;pop the content of eflags from stack to EFLAGS
ret

SECTION .bss
    resb 8192               ; This reserves 8KBytes of memory here
_sys_stack:
