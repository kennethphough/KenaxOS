/********************************************************************************
    KenaxOS
    0.3.0
*********************************************************************************
    kernel.c
    0.0.6
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

#include <message.h>
#include <video.h>

//Main function that is called from kernel_entry.asm
void main()
{
	int msgRet;  //store message returned from chckMsg

	init_MsgQue(&mqSys, MsgBuff, 64);  //initialize the message que

	MsgWrite(&mqSys, 0, MSG_BOOTED, 0, 0);  //write to message que that we have booted!

	//A while loop which continues until a MSG_SHTDWN is sent
	while((msgRet=chckMsg(&mqSys))!=0) {
		if(msgRet == 1)
			procMsg(&mqSys);
	}

// 	sys_cli();  //turn off interrupts

	set_attrib(RED, YELLOW);  //set screen background and foreground colors

	sysprint("\n\nKenaxOS has shutdown...\nYOU MAY SAFELY TURN YOUR COMPUTER OFF");  //tell the user that they can turn the computer off
}
