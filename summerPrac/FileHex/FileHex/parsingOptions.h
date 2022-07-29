#include "getopt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void parseParams(int argc, char** argv, struct parseOpt* opt);
int strtoi(char* str);
struct parseOpt {
	char* fileName;
	long offset;
	long size;
	int piece;
	int countPieces;
};

