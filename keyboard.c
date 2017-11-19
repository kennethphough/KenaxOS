/********************************************************************************
    kbd.c
    0.0.5
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
#include <message.h>
#include <video.h>

//Constants for keyboard LEDs
#define LED_SCRLLCK 1
#define LED_NUMLCK 2
#define LED_CAPSLCK 4
#define NOT_SHIFTED 0
#define SHIFTED 1

//Flags
unsigned char _CTRL, _ALT, _DELETE, _SHIFT;
unsigned char led_stat;
unsigned char E0_Expanded = 0;

//Buffers
unsigned char _ASCII = 0;

//Keyboard map for JIS 106 keyboard
unsigned char kbd_jis[2][128] =
{
	{
		0, 27,
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		'-', '^',
		'\b',
		'\t',
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '@', '[', '\n',
		0,
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', ':',
		0,0,
		']', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
		0,
		'*',
		0,
		' ',
		0,0,0,0,0,0,0,0,0,0,0,0,
		'7', '8', '9', '-',
		'4', '5', '6', '+',
		'1', '2', '3',
		'0', '.',
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		'_',
		0,0,0,0,0,0,0,0,0,
		'¥',
		0,0
	},

	{
		0, 27,
		'!', '"', '#', '$', '%', '&', '\'', '(', ')', '~',
		'=', '~',
		'\b',
		'\t',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '`', '{', '\n',
		0,
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', '+', '*',
		0,0,
		'}', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
		0,
		'*',
		0,
		' ',
		0,0,0,0,0,0,0,0,0,0,0,0,
		'7', '8', '9', '-',
		'4', '5', '6', '+',
		'1', '2', '3',
		'0', '.',
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		'_',
		0,0,0,0,0,0,0,0,0,
		'¥',
		0,0
	}
};

//Turn On/Off keyboard LEDs
void kbdLeds(unsigned char led) {
	outportb(0x60, 0xED);
	while(inportb(0x64) & 2);
	outportb(0x60, led);
	while(inportb(0x64) & 2);
}

void keyboard_init(void) {
	led_stat = 0;
	_CTRL = 0;
	_ALT = 0;
	_DELETE = 0;
	_SHIFT = 0;
}

void keyboard_hndlr(void) {
	unsigned int key = inportb(0x60);

	if(key==0x3A) {  //Caps lock
		led_stat ^= LED_CAPSLCK;
		kbdLeds(led_stat);
	} else if(key==0x45) {  //Num lock
		led_stat ^= LED_NUMLCK;
		kbdLeds(led_stat);
	} else if(key==0x46) {  //Scroll lock
		led_stat ^= LED_SCRLLCK;
		kbdLeds(led_stat);
	}

	//0xE0 Expanded
	if (key == 0xE0) {
		E0_Expanded = 1;
	}

	if(key & 0x80) {
		key ^= 0x80;
		if (key == 0x1D) {  //Left Ctrl
			_CTRL = 0;
		} else if(key == 0x38) {  //Left ALT
			_ALT = 0;
		} else if(key == 0x2A || key == 0x36) {
			_SHIFT = 0;
		}

		if(E0_Expanded == 1) {
			if(key == 0x1D) {  //Right Ctrl
				_CTRL = 0;
			} else if(key == 0x38) {  //Right ALT
				_ALT = 0;
			} else if(key == 0x53) {
				_DELETE = 0;
			}
		E0_Expanded = 0;
		}
	} else {
		if (key == 0x1D) {  //Left Ctrl
			_CTRL = 1;
		} else if(key == 0x38) {  //Left ALT
			_ALT = 1;
		} else if(key == 0x2A || key == 0x36) {
			_SHIFT = 1;
		}

		if(E0_Expanded == 1) {
			if(key == 0x1D) {  //Right Ctrl
				_CTRL = 1;
			} else if(key == 0x38) {  //Right ALT
				_ALT = 1;
			} else if(key == 0x53) {
				_DELETE = 1;
			}
		E0_Expanded = 0;
		}

		if((key <= 0x1C && key >= 0x02) || (key <= 0x28 && key >= 0x1E) || (key <= 0x35 && key >= 0x2B) || key == 0x37 || key == 0x39 || (key <= 0x53 && key >= 0x47) || key == 0x73 || key == 0x7D) {
			if(_SHIFT == 0) {
				MsgWrite(&mqSys, 0, MSG_KEYPRESS, 0, kbd_jis[0][key]);
			} else if(_SHIFT == 1) {
				MsgWrite(&mqSys, 0, MSG_KEYPRESS, 0, kbd_jis[1][key]);
			}
		}
	}

	if(_CTRL == 1 && _ALT == 1 && _DELETE == 1) {
		MsgWrite(&mqSys, 0, MSG_SHTDWN, 0, 0);
	}
}
