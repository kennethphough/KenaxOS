/********************************************************************************
    screen.c
    0.0.8
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

#include <string.h>
#include <video.h>
#include <io.h>
#include <asm.h>

unsigned short *vidmem = (unsigned short *)0xB8000;
int xcrs = 0;
int ycrs = 0;
int attrib;
int carry = 0;

//Clear screen
void cls(void) {
	unsigned short *vidmemp;
	int x, y;

	for(y=0;y<25;y++) {
		for(x=0;x<80;x++) {
			vidmemp = vidmem+((y*80)+x);
			*vidmemp = 0x20 | (WHITE << 8);
		}
	}
	xcrs = 0;
	ycrs = 0;
	update_crs();
}

//print string
void sysprint(unsigned char *txt) {
	while(*txt!=0) {
		putch(*txt);
		txt++;
	}
}

//print character to screen
void putch(unsigned char c) {
	unsigned short *vidmemp;

	if(c == 0x08) {
		if(carry == 0 && xcrs>10) {
			xcrs--;
			vidmemp = vidmem + ((ycrs*80)+xcrs);
			*vidmemp = 0x20 | (attrib << 8);
		} else if (carry!=0 && xcrs==0) {
			xcrs=79;
			ycrs--;
			carry--;
			vidmemp = vidmem + ((ycrs*80)+xcrs);
			*vidmemp = 0x20 | (attrib << 8);
		} else if (carry!=0 && xcrs != 0) {
			xcrs--;
			vidmemp = vidmem + ((ycrs*80)+xcrs);
			*vidmemp = 0x20 | (attrib << 8);
		}
	} else if(c == 0x09) {
		xcrs = (xcrs + 8) & ~(8-1);
	} else if(c == '\r') {
		xcrs = 0;
	} else if(c == '\n') {
		if(carry!=0)
			carry=0;
		newline();
	} else if(c >= ' ') {
		vidmemp = vidmem + ((ycrs*80)+xcrs);
		*vidmemp = c | (attrib << 8);
		xcrs++;
	}
	cursor_chck();
	update_crs();
	scroll_chck();
}

//make new line
void newline(void) {
	xcrs = 0;
	ycrs++;
	update_crs();
}

//check if cursor has reached the limit of the screen (80)
void cursor_chck(void) {
	if (xcrs >= 80) {
		xcrs = 0;
		carry++;
		ycrs++;
	}
}

//check to see if we need to scroll
void scroll_chck(void) {
	unsigned short *vidmemsrc = (unsigned short *)0xB8000;
	unsigned short *vidmemdest = (unsigned short *)0xB8000+80;
	int x, y;

	if(ycrs>=24) {
		for(y=0;y<24;y++) {
			for(x=0;x<80;x++) {
				*vidmemsrc++ = *vidmemdest++;
			}
		}
	xcrs = 0;
	ycrs--;
	update_crs();
	}
}

//set foreground and background colors
void set_attrib(int foreColor, int bgColor) {
	attrib = (bgColor << 4) | (foreColor);
}

//update cursor to new position
void update_crs(void) {
	unsigned int pos;

	pos = (ycrs*80)+xcrs;

	outportb(0x3D4, 14);
	outportb(0x3D5, pos >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, pos);
}

//initialize screen
void vid_init(void) {
	xcrs = 0;
	ycrs = 0;
	set_attrib(BWHITE, BLACK);
	cls();
}
