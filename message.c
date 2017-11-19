/********************************************************************************
    message.c
    0.0.7
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

#include <asm.h>
#include <init.h>
#include <message.h>
#include <video.h>
#include <message.h>
#include <keyboard.h>
#include <console.h>

MSG_QUE mqSys;
MSG MsgBuff[64];

//function definition to initiallize message que
void init_MsgQue(MSG_QUE *pMsgQue, MSG *pMsgBuff, INT32 array) {
	int i;

	pMsgQue->pMsgBuff = pMsgBuff;
	for(i=0; i<array; i++) {
		pMsgQue->pMsgBuff[i].class = 0;
		pMsgQue->pMsgBuff[i].message = MSG_NULL;
		pMsgQue->pMsgBuff[i].dirty = 0;
		pMsgQue->pMsgBuff[i].rParam = 0;
		pMsgQue->pMsgBuff[i].dParam = 0;
	}
	pMsgQue->size = array;
	pMsgQue->free = array;
	pMsgQue->r = 0;
	pMsgQue->w = 0;
}

//read message from que
MSG MsgGet(MSG_QUE *pMsgQue) {
	MSG tempMSG;

	if(pMsgQue->size == pMsgQue->free) {
		tempMSG.class = 0xFF;
		tempMSG.message = MSG_NULL;
		tempMSG.dirty = -1;
		tempMSG.rParam = -1;
		tempMSG.dParam = -1;

		return tempMSG;
	}

	tempMSG = pMsgQue->pMsgBuff[pMsgQue->r];

	pMsgQue->pMsgBuff[pMsgQue->r].dirty = 1;

	pMsgQue->r++;

	if(pMsgQue->r == pMsgQue->size)
		pMsgQue->r = 0;

	pMsgQue->free++;

	return tempMSG;
}

//write message to que
INT32 MsgWrite(MSG_QUE *pMsgQue, UINT8 class, UINT16 message, INT32 rParam, INT64 dParam) {
	if(pMsgQue->free == 0) {
		return -1;
	}

	pMsgQue->pMsgBuff[pMsgQue->w].class = class;
	pMsgQue->pMsgBuff[pMsgQue->w].message = message;
	pMsgQue->pMsgBuff[pMsgQue->w].dirty = 0;
	pMsgQue->pMsgBuff[pMsgQue->w].rParam = rParam;
	pMsgQue->pMsgBuff[pMsgQue->w].dParam = dParam;

	pMsgQue->w++;

	if(pMsgQue->w == pMsgQue->size)
		pMsgQue->w = 0;

	pMsgQue->free--;

	return 0;
}

//check if a shutdown message has been sent to que, if so return 0.  Also, check if message has already been read.
BOOL chckMsg(MSG_QUE *pMsgQue){
	if(pMsgQue->pMsgBuff[pMsgQue->r].message == MSG_SHTDWN) {
		return 0;
	} else if(pMsgQue->pMsgBuff[pMsgQue->r].dirty == 1) {
		return -1;
	} else {
		return 1;
	}
}

//message handler for KenaxOS.  --  Just a plain old switch()...case statement
void procMsg(MSG_QUE *pMsgQue) {
	MSG tempMSG;

	tempMSG = MsgGet(pMsgQue);

	switch (tempMSG.message) {
		case MSG_BOOTED:
			init();
			MsgWrite(pMsgQue, 0, MSG_INITED, 0, 0);
			break;
		case MSG_INITED:
			set_attrib(YELLOW, BLACK);
			sysprint("@@@  @@@  @@@@@@@@  @@@  @@@     @@     @@@  @@@\n");
			set_attrib(YELLOW, BLACK);
			sysprint(" @@ @@     @@        @@  @@     @@@@     @@  @@\n");
			sysprint(" @@@@      @@@@@     @@@ @@    @@  @@     @@@@\n");
			sysprint(" @@ @@     @@        @@ @@@    @@@@@@     @@@@\n");
			sysprint(" @@  @@    @@   @@   @@  @@    @@  @@    @@  @@\n");
			set_attrib(YELLOW, BLACK);
			sysprint("@@@@ @@@  @@@@@@@@  @@@  @@@  @@@  @@@  @@@  @@@\n");

			set_attrib(BWHITE, BLACK);
			sysprint("----------------------------\n");
			sysprint("KenaxOS\nVersion 0.3.0\nCopyright (c) 2006 Kenneth P. Hough\n\nKenaxOS>> ");

			MsgWrite(pMsgQue, 0, MSG_STI, 0, 0);
			break;
		case MSG_CLI:
			sys_cli();
			break;
		case MSG_STI:
			sys_sti();
			break;
		case MSG_KEYPRESS:
			_ASCII = tempMSG.dParam;
			console();
			break;
		case MSG_KEYRELEASE:
			break;
		case MSG_NULL:
			break;
		default:
			break;
	}
}
