#include "BigInt.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

BigInt* copy_BI(BigInt* num) {
	BigInt* copy = new_BI(num->size, num->sign);
	for (int i = 0; i < num->size; ++i) copy->data[i] = num->data[i];
	return copy;
}

void free_BI(BigInt* num) {
	free(num->data);
	free(num);
}

BigInt* removed_zeros(BigInt* number) {
	char* data_ptr = number->data;
	int new_size = number->size;
	while (*data_ptr == 0) data_ptr++, --new_size;
	if (new_size == number->size) return number;
	if (new_size == 0) {
		free(number->data);
		number->data = (char*)calloc(1, sizeof(char));
		number->size = 1;
		return number;
	}
	char* new_data = (char*)malloc(new_size * sizeof(char));
	for (int i = 0; i < new_size; ++i) {
		new_data[i] = data_ptr[i];
	}
	free(number->data);
	number->data = new_data;
	number->size = new_size;
	return number;
}

BigInt* new_BI(int size, int sign) {
	BigInt* number = (BigInt*)malloc(sizeof(BigInt));
	if (number == NULL) return NULL;

	number->data = (char*)calloc(size, sizeof(char));
	if (number->data == NULL) {
		free(number);
		return NULL;
	}
	number->size = size;
	number->sign = sign;

	return number;
}

void check_new_BI(BigInt* number) {
	if (number == NULL) {
		printf_s("ERROR: error on memory allocating\n");
		exit(-1);
	}
}

BigInt* str_to_BI(char* str) {
	int skip = 0;
	int length = strlen(str);
	int sign = 1;

	if (str[0] == '-') {
		sign = -1;
		str++;
		--length;
	}
	else if (str[0] == '+') {
		str++;
		--length;
	}

	while (skip < length && str[skip] == '0') {
		skip++;
	}
	if (skip == length) {
		BigInt* num = new_BI(1, 1);
		check_new_BI(num);
		return num;
	}
	BigInt* num = new_BI(length - skip, sign);
	check_new_BI(num);
	for (int i = 0; i < num->size; i++) {
		num->data[i] = str[i + skip] - '0';
	}
	return removed_zeros(num);
}

BigInt* adding_BI(BigInt* num_1, BigInt* num_2) {
	int sum_sign = 1;
	num_1 = copy_BI(num_1);
	num_2 = copy_BI(num_2);
	if (num_1->sign == num_2->sign) sum_sign = num_1->sign;
	sum_sign = num_1->size > num_2->size ? num_1->sign : num_2->sign;
	if (num_1->size == num_2->size) {
		int i = 0;
		while (i < num_1->size && num_1->data[i] == num_2->data[i]) i++;
		if (i == num_1->size) sum_sign = 1;
		else sum_sign = num_1->data[i] > num_2->data[i] ? num_1->sign : num_2->sign;
	}
	BigInt* sum = new_BI((num_1->size > num_2->size ? num_1->size : num_2->size) + 1, sum_sign);
	check_new_BI(sum);
	if (num_1->sign == -1 && num_2->sign == 1) {
		num_1->sign = 1;
		num_2->sign = -1;
	}

	char* sum_ptr = sum->data + sum->size - 1;
	char* num_1_ptr = num_1->data + num_1->size - 1;
	char* num_2_ptr = num_2->data + num_2->size - 1;

	for (int i = 0; i < num_1->size; i++, sum_ptr--, num_1_ptr--) {
		// num_1 всегда положительно
		*sum_ptr += *num_1_ptr;
	}

	sum_ptr = sum->data + sum->size - 1;
	for (int i = 0; i < num_2->size; i++, sum_ptr--, num_2_ptr--) {
		*sum_ptr += *num_2_ptr * num_2->sign * num_1->sign;
	}
	for (int i = sum->size - 1; i > 0; i--) {
		if (sum->data[i] < 0) {
			sum->data[i - 1] -= 1;
			sum->data[i] += 10;
		}
		else {
			sum->data[i - 1] += sum->data[i] / 10;
			sum->data[i] %= 10;
		}
	}
	if (sum->data[0] == -1) {
		sum->sign = -1;
		sum->data[0] = 0;
		sum->data[1] = 10 - sum->data[1];
	}
	free_BI(num_1);
	free_BI(num_2);
	return removed_zeros(sum);
}

BigInt* multiply(BigInt* num_1, BigInt* num_2) {
	BigInt* mult = new_BI(1, 1);
	check_new_BI(mult);

	for (int i = 0; i < num_1->size; i++) {
		BigInt* tmp = new_BI(i + 1 + num_2->size, 1);
		for (int j = num_2->size - 1; j >= 0; j--) {
			tmp->data[j + 1] += num_1->data[num_1->size - 1 - i] * num_2->data[j];
			tmp->data[j] += tmp->data[j + 1] / 10;
			tmp->data[j + 1] %= 10;
		}
		BigInt* mult_tmp = adding_BI(mult, tmp);
		free_BI(mult);
		free_BI(tmp);
		mult = mult_tmp;
	}
	mult->sign = num_1->sign * num_2->sign;
	return mult;
}

BigInt* substract(BigInt* num_1, BigInt* num_2) {
	BigInt* minus = str_to_BI("-1");
	BigInt* num_3 = multiply(num_2, minus);
	BigInt* sum_str = adding_BI(num_1, num_3);
	free_BI(num_3);
	free_BI(minus);
	return sum_str;
}

// return negative int if num_1 is greater than num_2, 0 if they are equals and positive int if num_1 less than num_2
int compare_BI(BigInt* num_1, BigInt* num_2) {
	if (num_1->sign * num_2->sign < 0) return num_2->sign;
	if (num_1->size != num_2->size) return num_1->sign * (num_2->size - num_1->size);
	for (int i = 0; i < num_1->size; ++i) {
		char digit_1 = num_1->data[i];
		char  digit_2 = num_2->data[i];
		if (digit_1 != digit_2) return (digit_2 - digit_1) * num_1->sign;
	}
	return 0;
}

BigInt* division(BigInt* num_1, BigInt* num_2) {
	BigInt* one = str_to_BI("1");
	check_new_BI(one);

	if (compare_BI(num_1, num_2) == 0) return one;

	int result_sign = num_1->sign * num_2->sign;

	num_1 = copy_BI(num_1); // make copy for num_1
	num_1->sign = 1; // make num_1 positive
	num_2 = copy_BI(num_2);
	num_2->sign = 1;

	BigInt* zero = str_to_BI("0");
	check_new_BI(zero);

	BigInt* counter = str_to_BI("0");
	check_new_BI(counter);

	BigInt* multiplier = new_BI(num_1->size - num_2->size, 1);
	multiplier->data[0] = 1;

	BigInt* step = multiply(num_2, multiplier);

	while (compare_BI(num_1, num_2) <= 0) {
		BigInt* tmp = substract(num_1, step);
		while (compare_BI(tmp, zero) > 0) {
			// уменьшаем шаг в 10 раз
			int new_multiplier_size = multiplier->size - 1;
			free_BI(multiplier);
			multiplier = new_BI(new_multiplier_size, 1);
			multiplier->data[0] = 1;
			free_BI(step);
			step = multiply(num_2, multiplier);

			tmp = substract(num_1, step);
		}
		free_BI(num_1);
		num_1 = tmp;
		tmp = adding_BI(counter, multiplier);
		free_BI(counter);
		counter = tmp;
	}
	free_BI(one);
	free_BI(zero);
	free_BI(num_1);
	free_BI(num_2);
	free_BI(multiplier);
	counter->sign = result_sign;
	return removed_zeros(counter);
}

void print_BI(BigInt* num) {
	if (num->sign == -1) {
		putchar('-');
	}
	for (int i = 0; i < num->size; i++) {
		putchar(num->data[i] + '0');
	}
}

