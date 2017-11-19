/********************************************************************************
    string.c
    0.0.2
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

int strcmp(char *str1, char *str2) {
	while(*str1 == *str2  && *str1 != 0 && str2 != 0) {
		str1++;
		str2++;
	}

	if(*str1 == *str2)
		return 0;

	return -1;
}

int strlen(char *str) {
	int i = 0;

	while(*str!=0) {
		i++;
		str++;
	}

	return i;
}

char *itoa(int integer) {
	int i=10000, num, temp, flag = 0;
	char *str;

	num = integer;

	if(num<0) {
		num = -num;
		*str++ = '-';
	}

	while(i!=1) {
		temp = num%i;

		if(temp!=0 || flag==1) {
			*str++ = '0' + temp;
			flag = 1;
			i/=10;
		}
	}
	*str = '\0';

	return str;
}

char *ltoa(long long_integer) {
	return 0;
}
