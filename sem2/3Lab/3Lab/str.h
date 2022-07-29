#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define SIZESTR 100

int my_strcmp(char* str, char* get);
int myn_strcmp(char* str, char* pattern, int counter);
int strlen(char* str);
int number_enter(char* str, char* pattern);
int find(char* str, char* pattern);
char* str_replace(char* str, char* pattern);
