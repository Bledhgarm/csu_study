#include <stdio.h> 

int main(void) {
	int a, b = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf_s("%d", a + b);
	return 0;
}