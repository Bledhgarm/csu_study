#include <stdio.h>

int main(void) {
	int a = 26;
	int b = 11;
	
	printf_s("%d + %d = %d\n", a, b, a + b);
	printf_s("%d - %d = %d\n", a, b, a - b);
	printf_s("%d * %d = %d\n", a, b, a * b);
	printf_s("%d / %d = %d\n", a, b, a / b);
	printf_s("%d %% %d = %d\n", a, b, a % b);

	return 0;
}