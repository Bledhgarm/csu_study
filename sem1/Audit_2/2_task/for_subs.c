#include <stdio.h>

int main(void) {
	int number;
	scanf_s("%d", &number);
	if (number % 2 == 0) {
		for (int i = 1; i <= number; i++)
			printf_s("%d ", i);
	}
	else {
		for (int i = number; i > 0; i--) {
			printf_s("%d ", i);
		}
	}
	return 0;
}