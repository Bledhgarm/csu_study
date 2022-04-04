#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char mass[100] = "";
	int array[100] = { 0 };
	int k = 0;
	printf("Enter a string:\n");
	gets(mass);
	int j = 0;
	for (unsigned int i = 0; i < strlen(mass); i++) {
		if (mass[i] >= '0' && mass[i] <= '9') {
			array[j] = array[j] * 10 + mass[i] - '0';
		}
		else {
			j++;
		}
	}
	int counter = 0;
	for (int i = 0; i < 100; i++) {
		if (array[i] > 0) {
			counter++;
		}
	}
	int* numbers = (int*)malloc(counter * sizeof(int));
	int z = 0;
	for (int i = 0; i < 100; i++) {
		if (array[i] != 0) {
			numbers[z] = array[i];
			z++;
		}
	}
	for (int i = 0; i < counter; i++) {
		numbers[i] *= numbers[i];
		printf("%d ", numbers[i]);
	}
	free(numbers);
	return 0;
}
