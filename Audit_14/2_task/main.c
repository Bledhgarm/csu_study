#include <stdio.h> 
#include <stdlib.h>

int main(void) {
	int number;
	int list_numbers[100] = { 0 };
	int combinations[100][100];
	scanf_s("%d", &number);
	int i = 0;
	while (number > 0) {
		list_numbers[i] = number % 10;
		number / 10;
		i++;
	}

	return 0;
}