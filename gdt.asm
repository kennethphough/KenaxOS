;********************************************************************************
;     gdt.asm
;     0.0.1
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

global gdt_flush

;;set up new GDT - void gdt_flush(void);
gdt_flush:
    lgdt [gdt_ptr]  ;;load GDT
    mov ax, 0x10
    mov ds, ax  ;;set Data Segment to 0x10 (kernel data segment)
    mov es, ax  ;;set the rest of the segment pointer to 0x10
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2  ;;Start executing the rest of the code from 0x08 (kernel code segment)
flush2:
    ret

;;GDT descriptor
gdt_ptr:
dw gdt_end-gdt_entry-1  ;;GDT size
dd gdt_entry  ;;GDT base


gdt_entry:  ;Start of GDT entry

;Null GDT entry - reserved by Intel
dd 0
dd 0

;Kernel code segment
dw 0xFFFF	;;Segment Limit 15:00
dw 0x0		;;Base Address 15:00

db 0x0		;;Base 23:16
db 10011010b	;;Type, S, DPL, P
db 11001111b	;;Segment Limit 19:16, AVL, L, D/B, G
db 0x0		;;Base 31:24

;Kernel data segment.
dw 0xFFFF	;;Segment Limit 15:00
dw 0x0		;;Base Address 15:00

db 0x0		;;Base 23:16
db 10010010b	;;Type, S, DPL, P
db 11001111b	;;Segment Limit 19:16, AVL, L, D/B, G
db 0x0		;;Base 31:24

;User code segment.
dw 0xFFFF	;;Segment Limit 15:00
dw 0x0		;;Base Address 15:00

db 0x0		;;Base 23:16
db 11111010b	;;Type, S, DPL, P
db 11001111b	;;Segment Limit 19:16, AVL, L, D/B, G
db 0x0		;;Base 31:24

;User data segment.
dw 0xFFFF	;;Segment Limit 15:00
dw 0x0		;;Base Address 15:00

db 0x0		;;Base 23:16
db 11110010b	;;Type, S, DPL, P
db 11001111b	;;Segment Limit 19:16, AVL, L, D/B, G
db 0x0		;;Base 31:24

gdt_end:  ;End of GDT entry.
