#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int array[32];
int bin(int number);
void dope(int counter);
int in();
int summ(int number);
void out(int *array);
int main(void) {	
	printf_s("Enter an input and output filenames:\n");
	int counter = 0;
	errno = 0;
	int number = in();
	if (errno != 0) {
		return 1;
	}
	if (array) {
		if (number >= 0) {
			for (int i = 0; i <= 31; i++) {
				array[i] = 0;
			}
			bin(number);
			out(array);
		}
		if (number < 0) {
			for (int i = 0; i <= 31; i++) {
				array[i] = 1;
			}
			number = abs(number);
			int counter = bin(number);
			for (int k = 31; k > 31 - counter; k--) {
				if (array[k] == 1) {
					array[k] = 0;
				}
				else {
					array[k] = 1;
				}
			}
			dope(counter);
			out(array);

		}
		printf_s("\n");
		system("pause");
		return 0;
	}
}


int bin(int number) {
	int counter = 0;
	int j = 31;
	while (number > 0) {
		for (int j = 31; j >= 0; j--) {
			if (number % 2 == 1) {
				array[j] = 1;
			}
			else {
				array[j] = 0;
			}
			number /= 2;
			counter += 1;
			if (number == 0) {
				break;
			}
		}
	}
	return counter;
}

int summ(int number) {
	int count_summa = 0;
	int counter = 0;
	while (number != 0) {
		counter += (number % 10);	
		number /= 10;
	}
	printf_s("%d\n", counter);
}

void dope(int counter) {
	for (int c = 31; c > 31 - counter; c--) {
		if (array[c] == 0) {
			array[c] = 1;
			break;
		}
		else {
			array[c] = 0;
		}
	} 
}


int in() {
	int number = 0;
	int counter = 0;
	char symb;
	char in_text[100] = { 0 };
	char max[10] = { '2','1','4','7','4','8','3','6','4','7' };
	char min[10] = { '2','1','4','7','4','8','3','6','4','8' };
	FILE *input;
	gets(in_text);
	if (fopen_s(&input, in_text, "r")) {
		perror("");
	}
	else {
		fscanf_s(input, "%c", &symb, 1);
		if (symb != '-') {
			fseek(input, 0, SEEK_SET);
		}
		while (fscanf_s(input, "%c", &symb, 1) != EOF) {
			counter++;
			if (symb < '0' || symb > '9') {
				printf_s("There is no number in this file");
				exit(1);
			}
		}
		fseek(input, 0, SEEK_SET);
		if (counter == 0) {
			printf_s("There is no number in this file");
			exit(1);
		}
		else if (counter > 10) {
			printf_s("IT's too big number");
			exit(1);
		}
		else if (counter < 10) {
			fscanf_s(input, "%d", &number);
		}
		else {
			fseek(input, 0, SEEK_SET);
			fscanf_s(input, "%c", &symb, 1);
			if (symb == '-') {
				for (int i = 0; i < 10; i++) {
					fscanf_s(input, "%c", &symb, 1);
					if (symb < min[i]) {
						break;
					}
					if (symb == min[i]) {
						continue;
					}
					if (symb > min[i]) {
						printf_s("overflow (negative)");
						exit(1);
					}
				}
			}
			else {
				fseek(input, 0, SEEK_SET);
				for (int i = 0; i < 10; i++) {
					fscanf_s(input, "%c", &symb, 1);
					if (symb < max[i]) {
						break;
					}
					if (symb == min[i]) {
						continue;
					}
					if (symb > max[i]) {
						printf_s("overflow (maximum)");
						exit(1);
					}
				}
			}
		}
		fseek(input, 0, SEEK_SET);
		fscanf_s(input, "%d", &number);
		summ(abs(number));
		fclose(input);
		return number;
	}	
}

void out(int *array) {
	char out_text[100] = { 0 };
	FILE *output;
	gets(out_text);
	if (fopen_s(&output, out_text, "w")) {
		perror("");
	}
	else {
		for (int i = 0; i < 32; i++) {
			fprintf_s(output, "%d", array[i]);
		}
		fclose(output);
	}
}
