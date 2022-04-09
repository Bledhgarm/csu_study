#pragma once

typedef struct {
	char* data;
	int size;
	int sign; // 1 or -1
} BigInt;

BigInt* copy_BI(BigInt* num);

void free_BI(BigInt* num);

BigInt* removed_zeros(BigInt* number);

BigInt* new_BI(int size, int sign);

void check_new_BI(BigInt* number);

BigInt* str_to_BI(char* str);

BigInt* adding_BI(BigInt* num_1, BigInt* num_2);

BigInt* multiply(BigInt* num_1, BigInt* num_2);

BigInt* substract(BigInt* num_1, BigInt* num_2);

int compare_BI(BigInt* num_1, BigInt* num_2);

BigInt* division(BigInt* num_1, BigInt* num_2);

void print_BI(BigInt* num);