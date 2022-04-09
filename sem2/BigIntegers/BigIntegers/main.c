#include <stdio.h>
#include <string.h>
#include "BigInt.h"


int main(int argc, char** argv) {
	/*char* str_1_c = (char*)malloc(10000 * sizeof(char));
	char* str_2_c = (char*)malloc(10000 * sizeof(char));
	printf("Enter first number\n");
	fgets(str_1_c, 1000, stdin);
	printf("Enter second number\n");
	fgets(str_2_c, 1000, stdin);
	char str_1[1000] = "";
	char str_2[1000] = "";
	int i = 0;
	while (str_1_c[i] != '\n') {
		if (str_1_c[i] == '\n') break;
		str_1[i] = str_1_c[i];
	}
	while (str_2_c[i] != '\n') {
		if (str_2_c[i] == '\n') break;
		str_2[i] = str_2_c[i];
	}*/
	BigInt* numb_1 = str_to_BI("13123123713241324132641324132444433243241234123421342314123");
	BigInt* numb_2 = str_to_BI("1");
	//char variations = '0';
	//scanf_s("%c", &variations, 1);
	BigInt* result = division(numb_1, numb_2);
	//switch (variations) {
	//case '1':
	//	result = adding_BI(numb_1, numb_2);
	//case '2':
	//	result = substract(numb_1, numb_2);
	//case '3':
	//	result = multiply(numb_1, numb_2);
	//case '4':
	//	result = division(numb_1, numb_2);
	//	/*default:
	//		printf("Wrong operation\n");
	//		return 1;*/
	//}
	printf("Result:\n");
	print_BI(result);
	free_BI(numb_1);
	free_BI(numb_2);
	free_BI(result);


	//while (1) {
	//	BigInt* r = multiply(str_1, str_2);
	//	free_BI(r);
	//}

	/*BigInt* div = division(str_1, str_2);
	print_BI(multiply(div, str_2));*/
	/*putchar('\n');
	printf("COMPARATOR TEST:\n");
	print_BI(str_1);
	int compare_result = compare_BI(str_1, str_2);
	putchar(compare_result > 0 ? '<' : compare_result < 0 ? '>' : '=');
	print_BI(str_2);*/
	return 0;
}