/*
    PPNumbers.cc
    Copyright (C) 2004 Uwe Reder

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Uwe Reder
    Uwe.Reder@GMX.net
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PPNumbers.h"

#define PPNUMBERS_MAX_DIGITS 21

static char *strcpy_reteos (char *dest, const char *src);
static char *number2txt_0_to_999 (char *dest, int number);

// This version of strcpy returns a pointer to the string-terminating \0
// of the <dest> string so that strings can be easily concatenated.

static char *strcpy_reteos (char *dest, const char *src) {
	char *dp = dest;
	const char *sp = src;
	char c;

	do {
		*dp++ = (c = *sp++);
	} while (c != '\0');

	return (dp - 1);
}

static char *digits_0_to_9[] = {"null", "eins", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun"};

char *digit2txt (char *dest, int number) {
	return (strcpy_reteos (dest, digits_0_to_9[number]));
}

char *number2txt (char *dest, char *ascii_digits) {

	int i;
	int num_thousands, num_digits;
	int int_number;
	int len = strlen (ascii_digits);
	char *p = dest;
	char *q = ascii_digits;

	if (len > PPNUMBERS_MAX_DIGITS) {
		return (NULL);
	}

	if (len == 1) {
		digit2txt (dest, atol(ascii_digits));
		return (dest);
	}

	num_thousands = (len-1) / 3;
	if (!(num_digits = (len % 3))) num_digits = 3;

	for (i=num_thousands; i>=0; i--) {

		char digits[4];
		int j;

		for (j=0; j<num_digits; j++) {
			digits[j] = *q++;
		}
		digits[j] = '\0';
		num_digits = 3;
		int_number = atol (digits);
		if (int_number > 0) {
			if (i<num_thousands) {	// no leading space
				p = strcpy_reteos (p, " ");
			}
			switch (i) {
				case 0:
					p = number2txt_0_to_999 (p, int_number);
					break;
				case 1:
					/* Tausend */
					if (int_number == 1) {
						p = strcpy_reteos (p, "ein");
					} else {
						p = number2txt_0_to_999 (p, int_number);
					}
					p = strcpy_reteos (p, " tausend");
					break;
				case 2:
					/* Millionen */
					if (int_number == 1) {
						p = strcpy_reteos (p, "eine million");
					} else {
						p = number2txt_0_to_999 (p, int_number);
						p = strcpy_reteos (p, " millionen");
					}
					break;
				case 3:
					/* Milliarden */
					if (int_number == 1) {
						p = strcpy_reteos (p, "eine milliarde");
					} else {
						p = number2txt_0_to_999 (p, int_number);
						p = strcpy_reteos (p, " milliarden");
					}
					break;
				case 4:
					/* Billionen */
					if (int_number == 1) {
						p = strcpy_reteos (p, "eine billion");
					} else {
						p = number2txt_0_to_999 (p, int_number);
						p = strcpy_reteos (p, " billionen");
					}
					break;
				case 5:
					/* Billiarden */
					if (int_number == 1) {
						p = strcpy_reteos (p, "eine billiarde");
					} else {
						p = number2txt_0_to_999 (p, int_number);
						p = strcpy_reteos (p, " billiarden");
					}
					break;
				case 6:
					/* Trillionen */
					if (int_number == 1) {
						p = strcpy_reteos (p, "eine trillion");
					} else {
						p = number2txt_0_to_999 (p, int_number);
						p = strcpy_reteos (p, " trillionen");
					}
					break;
			}
		}
	}

	return (dest);
}

static char *number2txt_0_to_999 (char *dest, int number) {

	char *p = dest;
	int digit_h = 0, digit_t, digit;

	if (number > 99) {
		digit_h = number / 100;
		if (digit_h == 1) {
			p = strcpy_reteos (p, "ein");
		} else {
			p = digit2txt (p, digit_h);
		}
		p = strcpy_reteos (p, " hundert");
		number -= digit_h * 100;
		if (number == 0) {
			return (p);
		}
		p = strcpy_reteos (p, " ");
	}

	if (number < 10) {
		return (digit2txt (p, number));
	}

	switch (number) {
		case 10:
			return (strcpy_reteos (p, "zehn"));
		case 11:
			return (strcpy_reteos (p, "elf"));
		case 12:
			return (strcpy_reteos (p, "zwölf"));
		case 16:
			return (strcpy_reteos (p, "sechzehn"));
		case 17:
			return (strcpy_reteos (p, "siebzehn"));
	}

	digit = number % 10;
	if (digit > 0) {
		if (digit == 1) {
			p = strcpy_reteos (p, "ein");
		} else {
			p = digit2txt (p, number % 10);
		}
	}

	digit_t = number / 10;
	if (digit_t == 1) {
		return (strcpy_reteos (p, "zehn"));
	}

	if (digit > 0) {
		p = strcpy_reteos (p, "und");
	}

	switch (digit_t) {
		case 2:
			return (strcpy_reteos (p, "zwanzig"));
		case 3:
			return (strcpy_reteos (p, "dreissig"));
		case 6:
			return (strcpy_reteos (p, "sechzig"));
		case 7:
			return (strcpy_reteos (p, "siebzig"));
	}

	p = digit2txt (p, digit_t);
	p = strcpy_reteos (p, "zig");

	return (p);
}

char *denominator2txt (char *buffer, char *ascii_digits) {
	int len, d;
	char *src, *dest;
	len = strlen(ascii_digits);
	if (len > 2) {
		d = atol(ascii_digits+len-2);
		if (d == 0 || d > 19) {
			number2txt (buffer, ascii_digits);
			strcat (buffer, "stel");
			return (buffer);
		} else {
			char *temp = new char [len+1];
			strncpy(temp, ascii_digits, len-2);
			temp[len-2] = '0'; temp[len-1] = '0'; temp[len] = '\0';
			number2txt (buffer, temp);
			strcat (buffer, " ");
			src = ascii_digits+len-2;
			dest = buffer+strlen(buffer);
		}
	} else {
		src = ascii_digits;
		dest = buffer;
		d = atol(src);
	}
	switch (d) {
		case 0:
			// would be division by zero - ignore ?!?
			break;
		case 1:
			if (buffer == dest) {
				strcpy (dest, " Ganzes");
			} else {
				strcpy (dest, "eintel");
			}
			break;
		case 2:
			if (buffer == dest) {
				strcpy (dest, "halb");
			} else {
				strcpy (dest, "zwotel");
			}
			break;
		case 3:
			strcpy (dest, "drittel");
			break;
		case 7:
			strcpy (dest, "siebtel");
			break;
		case 8:
			strcpy (dest, "achtel");
			break;
		default:
			number2txt (dest, src);
			strcat (dest, "tel");
			break;
	}
	return (dest);
}

