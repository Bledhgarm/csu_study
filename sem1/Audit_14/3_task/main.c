#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	int result = N * M - 1;
	printf_s("Result: %d", result);

	return 0;
}