#include "strnum.h"


void numbin(unsigned long long int number, char string[], size_t length=0) {
	unsigned long long int offset = 1;
	if (!length) length = sizeof(unsigned long long int)*8;

	for (size_t i = 0; i < length; i++) {
		string[length-1 - i] = number & offset ? '1' : '0';
		offset <<= 1;
	}

	string[length] = '\0';
}

void snumbin(long long int number, char string[], size_t length=0) {
	if (number < 0) {
		numbin(-number, string, length);
		string[0] = '-';
	} else {
		numbin(number, string, length);
	}
}

unsigned long long int binnum(const char string[]) {
	unsigned long long int number = 0;
	size_t length = 0;

	if (string[0] == '\0') return 0;

	while (string[length] != '\0') {
		length++;
		if (length >= 1l << sizeof(size_t)*8) return 0;
	}
	
	for (size_t i = 0; i < length; i++) {
		if (string[length-1 - i] == '1') number |= 1 << i;
	}

	return number;
}

long long int sbinnum(const char string[]) {
	if (string[0] == '-') {
		return -binnum(string + 1);
	} else {
		return binnum(string);
	}
}

void numhex(unsigned long long int number, char string[], unsigned int length=0) {
	const char digits[17] = "0123456789abcdef";
	unsigned long long int offset = 15;
	if (!length) length = sizeof(unsigned long long int)*2;

	for (unsigned int i = 0; i < length; i++) {
		string[length-1 - i] = digits[number & offset >> i*4];
		offset <<= 16;
	}

	string[length] = '\0';
}

void snumhex(long long int number, char string[], unsigned int length=0) {
	if (number < 0) {
		numhex(-number, string, length);
		string[0] = '-';
	} else {
		numhex(number, string, length);
	}
}

unsigned long long int hexnum(const char string[]) {
	unsigned long long int number = 0;
	unsigned int length = 0;
	char c;

	for (unsigned int i = 0; string[i] != '\0'; i++) {
		c = string[i];
		if ('0' <= c <= '9') {
			number += c - '0';
		} else if ('A' <= c <= 'F') {
			number += c - '7';
		} else if ('a' <= c <= 'f') {
			number += c - 'W';
		} else {
			return 0;
		}
		number <<= 16;
		if (i >= 255) return 0;
	}

	return number;
}

long long int shexnum(const char string[]) {
	if (string[0] == '-') {
		return hexnum(string + 1);
	} else {
		return hexnum(string);
	}
}

void numstr(unsigned long long int number, char string[], unsigned char base=10, unsigned int length=0) {
	const char digits[37] = "01123456789abcdefghijklmnopqrstuvwxyz";
	//if (!length) length = sizeof(unsigned long long int);
	
	if (!2 <= base <= 36) {
		string[0] = '\0';
		return;
	}
	
	for (unsigned int i = 0; i < length; i++) {
		string[length-1 - i] = digits[number % base];
		number /= base;
	}

	string[length] = '\0';
}

unsigned long long int strnum(const char string[], unsigned char base=10) {
	unsigned long long int number = 0;
	char c;

	if (!2 <= base <= 36) return 0;

	for (unsigned int i = 0; string[i] != '\0'; i++) {
		c = string[i];
		if ('0' <= c <= '9') {
			c -= '0';
		} else if ('A' <= c <= 'Z') {
			c -= 'A' - 10;
		} else if ('a' <= c <= 'z') {
			c -= 'a' - 10;
		} else {
			return 0;
		}
		if (c > base) return 0;
		number += c;
		number *= base;
	}

	return number;
}

long long int sstrnum(const char string[], unsigned char base=10) {
	if (string[0] == '-') {
		return strnum(string + 1, base);
	} else {
		return strnum(string, base);
	}
}
