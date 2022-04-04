#include <stdio.h>


int main(void) {
	int iArray[] = {422, 333, 888, 457, 999};
	char chArray[] = {'g','o', 'o', 'd', 'd', 'a', 'm', 'n'};
	for (int i = 0; i < sizeof(iArray) / sizeof(int); i++) {
		printf_s("%d ", iArray[i]);
	}
	printf_s("\n");
	for (int j = 0; j < sizeof(chArray) / sizeof(char); j++) {
		printf_s("%c ", chArray[j]);
	}


	return 0;
}