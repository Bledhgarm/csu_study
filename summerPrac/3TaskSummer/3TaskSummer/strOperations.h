#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tests(void);

int strtoi(const char* str, char** p, int* ret);
int my_itoa(char* buf, int bufSize, int value, int p);
int newSizeBuf(int value, int p);
char getDigitGiveSymb(int value, int p);
int absolute(int value);
int getNumberBase(const char** p);
int charToNum(char c, int* result);
int addChecked(int a, int b, int* r);
int subChecked(int a, int b, int* r);