#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "dyn_arr.h"

double sumDouble(int n, ...)
{
	double result = 0;
	double* ptr = &n;
	++((int*)ptr);
	while (n > 0)
	{
		result += *ptr;
		++ptr;
		--n;
	}
	return result;
}
double sum_double_via_stdargMACROSES(int n, ...)
{
	va_list arglist;
	va_start(arglist, n);
	double result = 0, i = 0;
	while (n > 0)
	{
		i = va_arg(arglist, double);
		result += i;
		--n;
	}
	va_end(arglist);
	return result;
}

char* concat(const char* s, ...) {

	dyn_array* strings = create(10);
	add(strings, s);

	va_list arglist;
	va_start(arglist, s);
	const char* str;
	do {
		str = va_arg(arglist, const char*);
		add(strings, str);
	} while (strlen(str) > 0);
	va_end(arglist);

	int length = 0;
	for (int i = 0; i < strings->size; ++i) {
		length += strlen(at(strings, i));
	}
	length++;
	char* result_str = (char*)calloc(length, sizeof(char));
	char* ptr = result_str;
	int remained_size = length * sizeof(char);
	for (int i = 0; i < strings->size; ++i) {
		str = at(strings, i);
		int len = strlen(str);
		strcpy_s(ptr, remained_size, str);
		ptr += len;
		remained_size -= len * sizeof(char);
	}

	return result_str;
}

int main()
{
	printf("%lf\n", sumDouble(4, 1.1, 2.2, 3.0, 0.1));
	printf("%lf\n", sum_double_via_stdargMACROSES(4, 1.1, 2.2, 3.0, 0.1));
	char* str1 = concat("one ", "two ", "three ", "four", "\0");
	printf("%s\n", str1);
	free(str1);
	str1 = concat("Happy ", "new ", "year!", "\0");
	printf("%s\n", str1);
	free(str1);
	str1 = concat("Hello ", "world!", "\0");
	printf("%s\n", str1);
	free(str1);
	system("pause");
	return 0;
}