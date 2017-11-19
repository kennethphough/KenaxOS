/********************************************************************************
    console.c
    0.0.4
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

#include <keyboard.h>
#include <string.h>
#include <video.h>
#include <message.h>

char commandBuffer[256];
int commandBuffPos = 0;

void console(void) {
	putch(_ASCII);

	if(_ASCII != '\n' && _ASCII != '\b') {
		commandBuffer[commandBuffPos] = _ASCII;
		commandBuffPos++;
	} else if(_ASCII == '\b') {
		commandBuffPos--;
	} else if(_ASCII == '\n') {
		commandBuffer[commandBuffPos] = '\0';
		if(strcmp(commandBuffer, "exit")==0) {
			sysprint("Use \"shutdown\" instead\n");
		} else if(strcmp(commandBuffer, "shutdown")==0) {
			MsgWrite(&mqSys, 0, MSG_SHTDWN, 0, 0);
		} else if(strcmp(commandBuffer, "cls")==0) {
			cls();
// 		} else if(strcmp(commandBuffer, "int")==0) {
// 			sysprint(itoa(256));
		} else if(strcmp(commandBuffer, "help")==0 || strcmp(commandBuffer, "?")==0) {
			sysprint("COMMAND HELP\n");
			sysprint("help - shows this list\n");
			sysprint("? - same as help\n");
			sysprint("cls - clears screen\n");
			sysprint("shutdown - Shutdown KenaxOS\n");
		} else if(commandBuffer[0] == '\0') {
		} else {
		sysprint("UNKNOWN COMMAND\n");
		}
	sysprint("KenaxOS>> ");
	commandBuffPos = 0;
	}
}
