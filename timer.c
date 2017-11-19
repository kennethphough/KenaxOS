/********************************************************************************
    timer.c
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

#include <io.h>

int ticks = 0;
int seconds = 0;

//increase ticks and add 1 to seconds every 100 ticks
void timer_hndlr(void) {
	ticks++;

	if(ticks%100==0)
		seconds++;
}

//wait for x amount of milliseconds
void wait(int num_ticks) {
	unsigned long newticks;

	newticks = ticks + num_ticks;
	while(ticks<newticks);
}

//change timer to interrupt 100 times per second
void timer_init(void) {
	outportb(0x43, 0x34);
	outportb(0x40, 0x9C);
	outportb(0x40, 0x2E);
}
