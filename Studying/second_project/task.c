#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 100

int main(void) {
	char *str = malloc(sizeof(char) * MAX_SIZE);
	for (int i = 0; i <= sizeof(str); i++) {
		scanf_s("%ñ", str);
		printf_s("%c", str[i]);
	}
	free(str);
	return 0;
}