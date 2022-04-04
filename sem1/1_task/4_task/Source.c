#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE


int main(void) {
	FILE *in;
	int number = 0;
	int broken = 0;
	int count = 0;
	int arr[MAX_SIZE] = { 0 };
	if (fopen_s(&in, "keyboard.txt", "r") == 0) {
		fscanf_s(in, "%d", &count);
		for (int i = 0; i < count; i++) {
			fscanf_s(in, "%d", &arr[i]);
		}
	}
	while ((fscanf_s(in, "%d", &number) != EOF)) {
		arr[number - 1]--;
}
	for (int i = 0; i < count; i++) {
		if (arr[i] < 0) {
			broken++;
		}
	}
	printf_s("%d", count);
	printf_s("\n");
	for (int i = 0; i < count; i++) {
		printf_s("%d", arr[i]);
	}
	printf_s("\n");
	printf_s("%d ", broken);
	return 0;
}
