#include <stdio.h>
#define ARRAY_SIZE 10
#define ARRAY_2_SIZE 5

void bubble_sort(int *array);
void out(int *another_array);

int main(void) {
	int array[ARRAY_SIZE];
	int another_array[ARRAY_2_SIZE];
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		scanf_s("%d", &array[i]);
	}
	bubble_sort(array);
	for (int n = ARRAY_SIZE-1, m = ARRAY_2_SIZE-1; n >= ARRAY_2_SIZE && m >= 0 ; n--, m--) {
		another_array[m] = array[n];
		}
	out(another_array);
	return 0;
}

void bubble_sort(int *array) {
	for (int j = 0; j < ARRAY_SIZE; j++) {
		for (int k = 1; k < ARRAY_SIZE; k++) {
			if (array[k] < array[k - 1]) {
				int tmp = array[k];
				array[k] = array[k - 1];
				array[k - 1] = tmp;
			}
		}
	}
}

void out(int *another_array) {
	for (int i = 0; i < ARRAY_2_SIZE; i++) {
		printf_s("%d ", another_array[i]);
	}
}
