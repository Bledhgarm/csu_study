#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "ru-RU");
	int var;
	do {
		scanf_s("%d", &var);
		if (var == 0) {
			return 1;
		}
		else if (var % 2 == 0) {
			printf_s("Чётное\n");
		}
		else {
			printf_s("Нечётное\n");
		}
	} while (var != 0);
	return 0;
}