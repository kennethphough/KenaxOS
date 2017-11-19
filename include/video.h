/********************************************************************************
    video.h
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

#ifndef __VIDEO_H
#define __VIDEO_H

/*COLORS*/
#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define WHITE 0x07
#define GRAY 0x08
#define LBLUE 0x09
#define LGREEN 0x0A
#define LCYAN 0x0B
#define LRED 0x0C
#define LMAGENTA 0x0D
#define YELLOW 0x0E
#define BWHITE 0x0F

extern void cls(void);
extern void sysprint(unsigned char *txt);
extern void putch(unsigned char c);
extern void newline(void);
extern void cursor_chck(void);
extern void scroll_chck(void);
extern void set_attrib(int foreColor, int bgColor);
extern void update_crs(void);
extern void vid_init(void);
extern int xcrs;

#endif
