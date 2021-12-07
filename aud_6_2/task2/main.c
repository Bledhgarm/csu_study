#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int size_a = 0;
	int size_b = 0;
	int sign = 0;
	scanf_s("%d", &size_a);
	scanf_s("%d", &size_b);
	int *arr_a = (int *)malloc(size_a * sizeof(int));
	int *arr_b = (int *)malloc(size_b * sizeof(int));
	for (int i = 0; i < size_a; i++) {
		sign = rand() % 2;
		arr_a[i] = (rand()% 2 ? 1 : -1) * (rand() % 41 - 10);
		printf_s("%d ", arr_a[i]);
	}
	printf_s("\n");
	for (int i = 0, j = 0; i < size_b; i++) {
		if (arr_a[j] != 0) {
			j = rand() % size_b;
			arr_b[i] = arr_a[j];
			arr_a[j] = 0;
			printf_s("%d ", arr_b[i]);
		}
		else {
			i--;
		}
	}
	free(arr_a);
	free(arr_b);
	return 0;
}