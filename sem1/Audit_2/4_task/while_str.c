#include <stdio.h>
#include <windows.h>

int main(void) {
	int var;
	scanf_s("%d", &var);
	while (var > 0) {
		int summ = 0;
		for (int i = 1; summ <= var; i++) {
			summ += i;
			if (summ > var) {
				
				printf_s("\n");
				Sleep(1);
			}
			if (summ <= var) {
				printf_s("%d ", i);
				Sleep(0.05);
			}
		
		}
		var = var / 2;
	}
	return 0;
}