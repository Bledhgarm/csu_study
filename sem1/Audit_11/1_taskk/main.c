#include <stdio.h>
#include <stdbool.h>
int main(void) {
	char symb;
	int n, k = 0;
	int result = 1;
	scanf_s("%d", &n);
	while (true) {
		symb = getc(stdin);
		if (symb == '\n') break;
		else if (symb == '!') k++;
	}
	while (n > 0) {
		result *= n;
		n -= k;
	}
	printf_s("%d\n", result);
	return 0;
}