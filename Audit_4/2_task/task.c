#include <stdio.h> 
#define ARRAY_SIZE 10

int main(void) {
	int array[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		scanf_s("%d", &array[i]);
	}
	for (int j = 0; j < ARRAY_SIZE; j++) {
		if (array[j] > 0) {
			printf_s("%d ", array[j]);
		}
	}
	return 0;
}