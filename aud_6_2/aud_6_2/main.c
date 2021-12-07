#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE_ARRAY 5

int main(void) {
	int n;
	int mass[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			mass[i][j] = rand() % 100 - 2;
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Enter array size: ");
	scanf_s("%d", &n);
	int *mass2 = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		mass2[i] = rand() % (2*n+1) - n;
		printf("%d ",mass2[i]);
	}
	return 0;
}