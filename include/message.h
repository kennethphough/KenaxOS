/********************************************************************************
    message.h
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

#ifndef __MESSAGE_H
#define __MESSAGE_H

#include <datatypes.h>

//Message structure
typedef struct _MESSAGE
{
	UINT8 class;
	UINT16 message;
	INT32 dirty;
	INT32 rParam;
	INT64 dParam;
} MSG;

//Message que structure
typedef struct _MSG_QUE
{
	MSG *pMsgBuff;
	INT32 size;
	INT32 free;
	UINT8 r, w;
} MSG_QUE;

/************************
      Message List
************************/
#define MSG_BOOTED 0x0000
#define MSG_INITED 0x0001
/*KenaxOS reserved - 0x0002*/
#define MSG_SHTDWN 0x0003
#define MSG_REBOOT 0x0004
/*KenaxOS reserved - 0x0005*/
/*KenaxOS reserved - 0x0006*/
/*KenaxOS reserved - 0x0007*/
#define MSG_CLI 0x0008
#define MSG_STI 0x0009
/*KenaxOS reserved - 0x000A*/
/*KenaxOS reserved - 0x000B*/
/*KenaxOS reserved - 0x000C*/
/*KenaxOS reserved - 0x000D*/
/*KenaxOS reserved - 0x000E*/
/*KenaxOS reserved - 0x000F*/
/*KenaxOS reserved - 0x0010*/
/*KenaxOS reserved - 0x0011*/
/*KenaxOS reserved - 0x0012*/
/*KenaxOS reserved - 0x0013*/
/*KenaxOS reserved - 0x0014*/
/*KenaxOS reserved - 0x0015*/
/*KenaxOS reserved - 0x0016*/
/*KenaxOS reserved - 0x0017*/
#define MSG_MEMCAP 0x0018
/*KenaxOS reserved - 0x0019*/
/*KenaxOS reserved - 0x001A*/
/*KenaxOS reserved - 0x001B*/
/*KenaxOS reserved - 0x001C*/
/*KenaxOS reserved - 0x001D*/
/*KenaxOS reserved - 0x001E*/
/*KenaxOS reserved - 0x001F*/
#define MSG_KEYPRESS 0x0020
#define MSG_KEYRELEASE 0x0021
/*KenaxOS reserved - 0x0022*/
/*KenaxOS reserved - 0x0023*/
/*KenaxOS reserved - 0x0024*/
/*KenaxOS reserved - 0x0025*/
/*KenaxOS reserved - 0x0026*/
/*KenaxOS reserved - 0x0027*/
/*KenaxOS reserved - 0x0028*/
/*KenaxOS reserved - 0x0029*/
/*KenaxOS reserved - 0x002A*/
/*KenaxOS reserved - 0x002B*/
/*KenaxOS reserved - 0x002C*/
/*KenaxOS reserved - 0x002D*/
/*KenaxOS reserved - 0x002E*/
/*KenaxOS reserved - 0x002F*/
/*KenaxOS reserved - 0x0030*/
/*KenaxOS reserved - 0x0031*/
/*KenaxOS reserved - 0x0032*/
/*KenaxOS reserved - 0x0033*/
/*KenaxOS reserved - 0x0034*/
/*KenaxOS reserved - 0x0035*/
/*KenaxOS reserved - 0x0036*/
/*KenaxOS reserved - 0x0037*/
/*KenaxOS reserved - 0x0038*/
/*KenaxOS reserved - 0x0039*/
/*KenaxOS reserved - 0x003A*/
/*KenaxOS reserved - 0x003B*/
/*KenaxOS reserved - 0x003C*/
/*KenaxOS reserved - 0x003D*/
/*KenaxOS reserved - 0x003E*/
/*KenaxOS reserved - 0x003F*/
/*KenaxOS reserved - 0x0040*/
/*KenaxOS reserved - 0x0041*/
/*KenaxOS reserved - 0x0042*/
/*KenaxOS reserved - 0x0043*/
/*KenaxOS reserved - 0x0044*/
/*KenaxOS reserved - 0x0045*/
/*KenaxOS reserved - 0x0046*/
/*KenaxOS reserved - 0x0047*/
/*KenaxOS reserved - 0x0048*/
/*KenaxOS reserved - 0x0049*/
/*KenaxOS reserved - 0x004A*/
/*KenaxOS reserved - 0x004B*/
/*KenaxOS reserved - 0x004C*/
/*KenaxOS reserved - 0x004D*/
/*KenaxOS reserved - 0x004E*/
/*KenaxOS reserved - 0x004F*/
/*KenaxOS reserved - 0x0050*/
/*KenaxOS reserved - 0x0051*/
/*KenaxOS reserved - 0x0052*/
/*KenaxOS reserved - 0x0053*/
/*KenaxOS reserved - 0x0054*/
/*KenaxOS reserved - 0x0055*/
/*KenaxOS reserved - 0x0056*/
/*KenaxOS reserved - 0x0057*/
/*KenaxOS reserved - 0x0058*/
/*KenaxOS reserved - 0x0059*/
/*KenaxOS reserved - 0x005A*/
/*KenaxOS reserved - 0x005B*/
/*KenaxOS reserved - 0x005C*/
/*KenaxOS reserved - 0x005D*/
/*KenaxOS reserved - 0x005E*/
/*KenaxOS reserved - 0x005F*/
/*KenaxOS reserved - 0x0060*/
/*KenaxOS reserved - 0x0061*/
/*KenaxOS reserved - 0x0062*/
/*KenaxOS reserved - 0x0063*/
/*KenaxOS reserved - 0x0064*/
/*KenaxOS reserved - 0x0065*/
/*KenaxOS reserved - 0x0066*/
/*KenaxOS reserved - 0x0067*/
/*KenaxOS reserved - 0x0068*/
/*KenaxOS reserved - 0x0069*/
/*KenaxOS reserved - 0x006A*/
/*KenaxOS reserved - 0x006B*/
/*KenaxOS reserved - 0x006C*/
/*KenaxOS reserved - 0x006D*/
/*KenaxOS reserved - 0x006E*/
/*KenaxOS reserved - 0x006F*/
/*KenaxOS reserved - 0x0070*/
/*KenaxOS reserved - 0x0071*/
/*KenaxOS reserved - 0x0072*/
/*KenaxOS reserved - 0x0073*/
/*KenaxOS reserved - 0x0074*/
/*KenaxOS reserved - 0x0075*/
/*KenaxOS reserved - 0x0076*/
/*KenaxOS reserved - 0x0077*/
/*KenaxOS reserved - 0x0078*/
/*KenaxOS reserved - 0x0079*/
/*KenaxOS reserved - 0x007A*/
/*KenaxOS reserved - 0x007B*/
/*KenaxOS reserved - 0x007C*/
/*KenaxOS reserved - 0x007D*/
/*KenaxOS reserved - 0x007E*/
/*KenaxOS reserved - 0x007F*/
/*KenaxOS reserved - 0x0080*/
/*KenaxOS reserved - 0x0081*/
/*KenaxOS reserved - 0x0082*/
/*KenaxOS reserved - 0x0083*/
/*KenaxOS reserved - 0x0084*/
/*KenaxOS reserved - 0x0085*/
/*KenaxOS reserved - 0x0086*/
/*KenaxOS reserved - 0x0087*/
/*KenaxOS reserved - 0x0088*/
/*KenaxOS reserved - 0x0089*/
/*KenaxOS reserved - 0x008A*/
/*KenaxOS reserved - 0x008B*/
/*KenaxOS reserved - 0x008C*/
/*KenaxOS reserved - 0x008D*/
/*KenaxOS reserved - 0x008E*/
/*KenaxOS reserved - 0x008F*/
/*KenaxOS reserved - 0x0090*/
/*KenaxOS reserved - 0x0091*/
/*KenaxOS reserved - 0x0092*/
/*KenaxOS reserved - 0x0093*/
/*KenaxOS reserved - 0x0094*/
/*KenaxOS reserved - 0x0095*/
/*KenaxOS reserved - 0x0096*/
/*KenaxOS reserved - 0x0097*/
/*KenaxOS reserved - 0x0098*/
/*KenaxOS reserved - 0x0099*/
/*KenaxOS reserved - 0x009A*/
/*KenaxOS reserved - 0x009B*/
/*KenaxOS reserved - 0x009C*/
/*KenaxOS reserved - 0x009D*/
/*KenaxOS reserved - 0x009E*/
/*KenaxOS reserved - 0x009F*/
/*KenaxOS reserved - 0x00A0*/
/*KenaxOS reserved - 0x00A1*/
/*KenaxOS reserved - 0x00A2*/
/*KenaxOS reserved - 0x00A3*/
/*KenaxOS reserved - 0x00A4*/
/*KenaxOS reserved - 0x00A5*/
/*KenaxOS reserved - 0x00A6*/
/*KenaxOS reserved - 0x00A7*/
/*KenaxOS reserved - 0x00A8*/
/*KenaxOS reserved - 0x00A9*/
/*KenaxOS reserved - 0x00AA*/
/*KenaxOS reserved - 0x00AB*/
/*KenaxOS reserved - 0x00AC*/
/*KenaxOS reserved - 0x00AD*/
/*KenaxOS reserved - 0x00AE*/
/*KenaxOS reserved - 0x00AF*/
/*KenaxOS reserved - 0x00B0*/
/*KenaxOS reserved - 0x00B1*/
/*KenaxOS reserved - 0x00B2*/
/*KenaxOS reserved - 0x00B3*/
/*KenaxOS reserved - 0x00B4*/
/*KenaxOS reserved - 0x00B5*/
/*KenaxOS reserved - 0x00B6*/
/*KenaxOS reserved - 0x00B7*/
/*KenaxOS reserved - 0x00B8*/
/*KenaxOS reserved - 0x00B9*/
/*KenaxOS reserved - 0x00BA*/
/*KenaxOS reserved - 0x00BB*/
/*KenaxOS reserved - 0x00BC*/
/*KenaxOS reserved - 0x00BD*/
/*KenaxOS reserved - 0x00BE*/
/*KenaxOS reserved - 0x00BF*/
/*KenaxOS reserved - 0x00C0*/
/*KenaxOS reserved - 0x00C1*/
/*KenaxOS reserved - 0x00C2*/
/*KenaxOS reserved - 0x00C3*/
/*KenaxOS reserved - 0x00C4*/
/*KenaxOS reserved - 0x00C5*/
/*KenaxOS reserved - 0x00C6*/
/*KenaxOS reserved - 0x00C7*/
/*KenaxOS reserved - 0x00C8*/
/*KenaxOS reserved - 0x00C9*/
/*KenaxOS reserved - 0x00CA*/
/*KenaxOS reserved - 0x00CB*/
/*KenaxOS reserved - 0x00CC*/
/*KenaxOS reserved - 0x00CD*/
/*KenaxOS reserved - 0x00CE*/
/*KenaxOS reserved - 0x00CF*/
/*KenaxOS reserved - 0x00D0*/
/*KenaxOS reserved - 0x00D1*/
/*KenaxOS reserved - 0x00D2*/
/*KenaxOS reserved - 0x00D3*/
/*KenaxOS reserved - 0x00D4*/
/*KenaxOS reserved - 0x00D5*/
/*KenaxOS reserved - 0x00D6*/
/*KenaxOS reserved - 0x00D7*/
/*KenaxOS reserved - 0x00D8*/
/*KenaxOS reserved - 0x00D9*/
/*KenaxOS reserved - 0x00DA*/
/*KenaxOS reserved - 0x00DB*/
/*KenaxOS reserved - 0x00DC*/
/*KenaxOS reserved - 0x00DD*/
/*KenaxOS reserved - 0x00DE*/
/*KenaxOS reserved - 0x00DF*/
/*KenaxOS reserved - 0x00E0*/
/*KenaxOS reserved - 0x00E1*/
/*KenaxOS reserved - 0x00E2*/
/*KenaxOS reserved - 0x00E3*/
/*KenaxOS reserved - 0x00E4*/
/*KenaxOS reserved - 0x00E5*/
/*KenaxOS reserved - 0x00E6*/
/*KenaxOS reserved - 0x00E7*/
/*KenaxOS reserved - 0x00E8*/
/*KenaxOS reserved - 0x00E9*/
/*KenaxOS reserved - 0x00EA*/
/*KenaxOS reserved - 0x00EB*/
/*KenaxOS reserved - 0x00EC*/
/*KenaxOS reserved - 0x00ED*/
/*KenaxOS reserved - 0x00EE*/
/*KenaxOS reserved - 0x00EF*/
/*KenaxOS reserved - 0x00F0*/
/*KenaxOS reserved - 0x00F1*/
/*KenaxOS reserved - 0x00F2*/
/*KenaxOS reserved - 0x00F3*/
/*KenaxOS reserved - 0x00F4*/
/*KenaxOS reserved - 0x00F5*/
/*KenaxOS reserved - 0x00F6*/
/*KenaxOS reserved - 0x00F7*/
/*KenaxOS reserved - 0x00F8*/
/*KenaxOS reserved - 0x00F9*/
/*KenaxOS reserved - 0x00FA*/
/*KenaxOS reserved - 0x00FB*/
/*KenaxOS reserved - 0x00FC*/
/*KenaxOS reserved - 0x00FD*/
/*KenaxOS reserved - 0x00FE*/
/*KenaxOS reserved - 0x00FF*/

//NUL Message
#define MSG_NULL 0xFFFF

/************************
      Message Type
************************/


extern MSG_QUE mqSys;
extern MSG MsgBuff[64];

extern void init_MsgQue(MSG_QUE *pMsgQue, MSG *pMsgBuff, INT32 array);
extern MSG MsgGet(MSG_QUE *pMsgQue);
extern INT32 MsgWrite(MSG_QUE *pMsgQue, UINT8 class, UINT16 message, INT32 rParam, INT64 dParam);
extern BOOL chckMsg(MSG_QUE *pMsgQue);
extern void procMsg(MSG_QUE *pMsgQue);

#endif
