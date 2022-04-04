#include <stdio.h> 

void get_digits(int *numbers);
int comp(int first, int second, int third, int counter, int summ_1, int summ_2);
void out_digits(result);

int main(void) {
	int result = 0;
	int counter = 0;
	int summ_1 = 0;
	int summ_2 = 0;
	int *numbers = (int *)malloc(3 * sizeof(int));
	get_digits(numbers);
	result = comp(numbers[0], numbers[1], numbers[2], counter, summ_1, summ_2);
	result = comp(numbers[1], numbers[2], numbers[0], counter, summ_1, summ_2);
	result = comp(numbers[0], numbers[2], numbers[1], counter, summ_1, summ_2);
	out_digits(result);

	free(numbers);
	return 0;
}

void get_digits(int *numbers) {
	FILE *input;
	if (fopen_s(&input, "input.txt", "r")) {
		printf_s("ERROR");
		_fcloseall();
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		fscanf_s(input, "%d", &numbers[i]);
	}
}

void out_digits(result) {
	FILE *output;
	fopen_s(&output, "result.txt", "w");
	fprintf_s(output, "%d", result);
}


int comp(int first, int second, int third, int counter, int summ_1, int summ_2) {
	while (first + second <= third) {
		if (counter % 2 == 0) {
			first++;
			summ_1++;
		}
		else {
			second++;
			summ_2++;
		}
		counter++;
	}
	return summ_1 + summ_2;
}
