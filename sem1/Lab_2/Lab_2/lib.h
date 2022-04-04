#include <stdio.h> 
#include <errno.h>
#include <stdlib.h>

struct inform_matrix find_size();
double **create_matrix(int columns, int rows);
double **get_matrix(struct inform_matrix s);
void erase_matrix(double **array, int rows);
double **addition(double **inp_array_1, double **inp_array_2, int columns, int rows);
void out_matrix(double **result_matrix, int columns, int rows);
double **substraction(double **inp_array_1, double **inp_array_2, int columns, int rows);
double **transpose(double **inp_array, int columns, int rows);
double **composition(double **inp_array_1, double **inp_array_2, int columns_2, int rows_1, int columns_1, int rows_2);
struct inform_matrix {
	int columns;
	int rows;
	char in_text[100];
};
double **get_matrix(struct inform_matrix s) {
	FILE *input;
	if (fopen_s(&input, s.in_text, "r")) {
		perror("");
		exit(0);
	}
	else {
		double **inp_array = create_matrix(s.columns, s.rows);
		for (int i = 0; i < s.rows; i++) {
			for (int j = 0; j < s.columns; j++) {
				fscanf_s(input, "%lf", &inp_array[i][j]);
			}
		}
		fclose(input);
		return inp_array;
	}
}

struct inform_matrix find_size() {
	struct inform_matrix s;
	s.columns = s.rows = 0;
	char symb = '0';
	int checker = 0;
	FILE *input;
	scanf_s("%s", s.in_text, 100);
	if (fopen_s(&input, s.in_text, "r")) {
		perror("");
		exit(0);
	}
	else {
		do {
			do {
				fscanf_s(input, "%c", &symb, 1);
			} while (symb != ' ' && symb != '\n');
			s.columns++;
		} while (symb != '\n');
		fseek(input, 0, SEEK_SET);
		s.rows++;
		int checker = 0;
		while (fscanf_s(input, "%c", &symb, 1) != EOF) {
			checker++;
			if (symb == ' ') {
				checker--;
			}
			if (symb == '\n') {
				checker--;
				s.rows++;
				if (checker != s.columns) {
					printf_s("Wrong type of matrix");
					exit(1);
				}
				checker = 0;
			}
		}
		if (abs(symb) < '0' || abs(symb) > '9') {
			printf_s("Error, sign in file");
			exit(1);
		}
		fclose(input);
		return s;
	}
}

double **create_matrix(int columns, int rows) {
	double **array = (double **)malloc(rows * sizeof(double *));
	if (array) {
		for (int i = 0; i < rows; i++) {
			array[i] = (double *)malloc(columns * sizeof(double));
		}
	}
	return array;
}

double **addition(double **inp_array_1, double **inp_array_2, int columns, int rows) {
	double **result_matrix = create_matrix(columns, rows);
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			result_matrix[j][i] = inp_array_1[j][i] + inp_array_2[j][i];
		}
	}
	return result_matrix;
}

double **substraction(double **inp_array_1, double **inp_array_2, int columns, int rows) {
	double **result_matrix = create_matrix(columns, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			result_matrix[i][j] = inp_array_1[i][j] - inp_array_2[i][j];
		}
	}
	return result_matrix;
}

double **transpose(double **inp_array, int columns, int rows) {
	double **result_matrix = create_matrix(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			result_matrix[j][i] = inp_array[i][j];
		}
	}
	return result_matrix;
}

double **composition(double **inp_array_1, double **inp_array_2, int columns_2, int rows_1, int columns_1, int rows_2) {
	double **result_matrix = create_matrix(columns_2, rows_1);
	if (rows_1 == columns_2) {
		for (int i = 0; i < rows_1; i++) {
			for (int j = 0; j < columns_2; j++) {
				result_matrix[i][j] = 0;
				for (int k = 0; k < columns_1; k++) {
					result_matrix[i][j] += inp_array_1[i][k] * inp_array_2[k][j];
				}
			}
		}
	}
	else {
		printf_s("Error, wrong sizes of matrices");
		exit(1);
	}
	return result_matrix;
}

void out_matrix(double **result_matrix, int columns, int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf_s("%g ", result_matrix[i][j]);
		}
		printf_s("\n");
	}
}

void erase_matrix(double **array, int rows) {
	for (int i = 0; i < rows; i++) {
		free(array[i]);
	}
	free(array);
}