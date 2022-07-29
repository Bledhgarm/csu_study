#include "parsingOptions.h"


void parseParams(int argc, char** argv, struct parseOpt* opt) {
	int c;
	while ((c = getopt(argc, argv, "i:o:l:g:n:f:")) != -1) {
		switch (c) {
		case 'i':
			opt->fileName = malloc(strlen(optarg) + 1);
			strcpy_s(opt->fileName, (strlen(optarg) + 1) * sizeof(char), optarg);
			break;

		case 'o':
			opt->offset = atol(optarg);
			break;
			
		case 'l':
			opt->size = atol(optarg);
			break;

		case 'g':
			if (strcmp(optarg, "byte") == 0) opt->piece = 1;
			else if (strcmp(optarg, "word") == 0)  opt->piece = 2;
			else if (strcmp(optarg, "dword") == 0) opt->piece = 4; 
			else {
				fprintf(stderr, "Unkown arg");
				exit(EXIT_FAILURE);
			}
			break;

		case 'n':
			opt->countPieces = atol(optarg);
			break;

		default:
			fprintf(stderr, "Unkown arg");
			exit(EXIT_FAILURE);
			break;
		}
	}
}


long getSizeFile(FILE* file) {
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	rewind(file);
	return size;
}

int strtoi(char* str) {
	int numberBase = 16;
	int result = 0;
	int multiplier = 1;
	int lengthStr = strlen(str);
	int check;
	for (int i = lengthStr; i > 0; i--) {
		int symb = (int)*str;
		result = symb * multiplier;
		multiplier *= numberBase;
	}
	return result;
}

char* readDataFromFile(struct parseOpt* opt) {
	char* str = malloc(opt->piece);
	FILE* file;
	if (file = fopen("fileHex.txt", "r") == NULL) {
		exit(EXIT_FAILURE);
	}
	fread_s(str, opt->piece, sizeof(char), opt->piece, file);
	return str;
}

void stringToHex(struct parseOpt* opt) {
	char* str = malloc(opt->piece);
	str = readDataFromFile(opt);
	int hexDig = strtoi(str);
}

void printHexToFile(struct parseOpt* opt) {

}

