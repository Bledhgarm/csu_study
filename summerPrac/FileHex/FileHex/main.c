#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "parsingOptions.h"
#include "getopt.h"


int main(int argc, char* argv[], char* envp[]) {
	struct parseOpt opt;
	parseParams(argc, argv, &opt);
	printf("%s\n", opt.fileName);
	printf("%ld\n", opt.offset);
	printf("%ld\n", opt.size);
	printf("%d\n", opt.piece);
	printf("%d\n", opt.countPieces);
}
