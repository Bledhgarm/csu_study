#include <stdio.h> 

int main(void) {
	char symb;
	int column;
	int length;
	scanf_s("%c%d%d", &symb, 1, &column, &length);
	for (int i = 1; i <= column; i++) {
		printf_s("\n%c ", symb);
		for (int j = 1; j <= length-1; j++) {
			printf_s("%c ", symb);
		}	
	}
	return 0;
}