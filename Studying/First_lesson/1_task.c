#include <stdio.h> 
#include <locale.h>

int main (void) {

	setlocale(LC_ALL, "ru-RU");
	printf_s("Hello world!\n");
	printf_s("Привет, мир!");
	return 0;
}