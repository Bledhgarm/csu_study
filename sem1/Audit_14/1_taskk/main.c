#include <stdio.h>
#define SIZE_WORDS strlen(argv[1])
int main(int argc, char **argv) {
	int counter[1000] = { 0 };
	int amount_repeats = 0;
	for (int i = 0; i < SIZE_WORDS; i++) {
		counter[argv[1][i]]++;
	}
	for (int i = 0; i < SIZE_WORDS; i++) {
		if (counter[argv[1][i]] > 1) {
			amount_repeats++;
			printf_s("%c", argv[1][i]);
			counter[argv[1][i]] = 0;
		}
	}
	printf("\nAmount of repeats symbols:\n%d", amount_repeats);
	return 0;
}

