#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "ru-RU");
	int var;
	scanf_s("%d", &var);
	if (var % 2 == 0) {
		printf("׸����");
	}
	else {
		printf_s("��������");
	}
	printf_s("%d", - 7 % 2);
// �� ��� ��� var % 2 == 0 ? printf_s("׸����") : printf_s("��������");
}