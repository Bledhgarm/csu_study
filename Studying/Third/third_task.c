#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "ru-RU");
	int var;
	scanf_s("%d", &var);
	if (var % 2 == 0) {
		printf("Чётное");
	}
	else {
		printf_s("Нечётное");
	}
	printf_s("%d", - 7 % 2);
// ну или так var % 2 == 0 ? printf_s("Чётное") : printf_s("Нечётное");
}