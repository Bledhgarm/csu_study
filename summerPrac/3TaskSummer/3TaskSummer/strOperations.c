#include "strOperations.h"



int my_itoa(char* buf, int bufSize, int value, int p) {
	if (buf == NULL) {
		return newSizeBuf(value, p);
	}
	if (bufSize < newSizeBuf(value, p)) {
		return 0;
	}
	int counter = 0;
	int neg_flag = 0;
	if (value < 0) {
		neg_flag = 1;
	}
	do {
		char symb = getDigitGiveSymb(value, p);
		buf[counter] = symb;
		counter++;
		value /= p;
	} while (value != 0);
	if (neg_flag) {
		buf[counter] = '-';
		counter++;
	}
	char tmp;
	for (int i = 0, j = counter - 1; i < j; i++, j--) {
		tmp = buf[i];
		buf[i] = buf[j];
		buf[j] = tmp;
	}
	return counter;
}

int absolute(int value) {
	if (value < 0) {
		return value * (-1);
	}
	return value;
}

char getDigitGiveSymb(int value, int p) {
	char symb;
	symb = absolute(value % p);
	if ((symb >= 0) && (symb <= 9)) {
		symb += '0';
	}
	else {
		symb += 55;
	}

	return symb;
}

int newSizeBuf(int value, int p) {
	if (value == 0) {
		return 1;
	}
	int counter = 0;
	if (value < 0) {
		counter++;
	}
	while (value != 0) {
		value /= p;
		counter++;
	}
	return counter;
}


int strtoi(const char* str, char** p, int* ret) {
	int isNegative = 0;
	int check;
	if (*str == '-') {
		isNegative = 1;
		str++;
	}
	int numberBase = getNumberBase(&str);
	const char* numberStart = str;
	if (*str == 0) {
		return 0;
	}
	while (*str != 0) {
		int digit;
		int success = charToNum(*str, &digit); //проверка на ошибки (некоректное значение или на корректность системы счисления) 
		if (!success || digit >= numberBase) {
			*p = str;
			return 0;
		}
		str++;
	}
	str--; //возвращаемся на последний символ строки
	int result = 0;
	int multiplier = 1;
	for (int i = 0; str >= numberStart; str--, i++) {
		int digit;
		charToNum(*str, &digit);
		if (isNegative) {
			check = subChecked(result, digit * multiplier, &result);
		}
		else {
			check = addChecked(result, digit * multiplier, &result);
		}
		if (check == 0) {
			if (p != NULL) *p = str;
			return 0;
		}
		multiplier *= numberBase;
	}
	*ret = result;
	return 1;
}
int getNumberBase(const char** p) {
	char c = **p;
	if (c == 'b') {
		(*p)++;
		return 2;
	}
	if (c == '0') {
		(*p)++;
		char n = **p;

		if (n == 'x') {
			(*p)++;
			return 16;
		}
		//если восьмеричная система счисления, то оставляем в начале строки 0,
		//чтоб не обрабатывать случай когда само число 0
		(*p)--;
		return 8;
	}
	return 10;
}



int charToNum(char c, int* result) {
	if (c >= '0' && c <= '9') {
		*result = c - '0';
		return 1;
	}

	if (c >= 'A' && c <= 'F') {
		*result = c - 'A' + 10;
		return 1;
	}

	return 0;
}

int addChecked(int a, int b, int* r) {
	if (a > INT_MAX - b)
		return 0;

	*r = a + b;
	return 1;
}

int subChecked(int a, int b, int* r) {
	if (a < INT_MIN + b)
		return 0;

	*r = a - b;
	return 1;
}