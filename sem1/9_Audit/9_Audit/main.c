#include <stdio.h> 

int fib(int number);
int main(int argc, char **argv) {
	int number;
	scanf_s("%d", &number);
	printf_s("%d", fib(number-1));
	return 0;
}

int fib(int number) {
	if (number == 0) {
		return 0;
	}
	else if (number == 1 || number == 2) {
		return 1;
	}
	return fib(number - 1) + fib(number - 2);
}