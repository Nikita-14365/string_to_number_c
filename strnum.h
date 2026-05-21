#pragma once
#ifndef _STRNUM_H_
#define _STRNUM_H_


void numbin(unsigned long long int, char [], unsigned int);

void snumbin(long long int, char [], unsigned int);

unsigned long long int binnum(const char []);

long long int sbinnum(const char []);

void numhex(unsigned long long int, char [], unsigned int);

void snumhex(long long int, char [], unsigned int);

unsigned long long int hexnum(const char []);

long long int shexnum(const char []);

void numstr(unsigned long long int, char [], unsigned char, unsigned int);

unsigned long long int strnum(const char [], unsigned char);

long long int sstrnum(const char [], unsigned char);

#endif
