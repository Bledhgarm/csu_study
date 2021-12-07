#include <stdio.h> 
#include <errno.h>
#include <stdlib.h>
#include "lib.h"
struct inform_matrix find_size();
double **create_matrix(int columns, int rows);
double **get_matrix(struct inform_matrix s);
void erase_matrix(double **array, int rows);
double **addition(double **inp_array_1, double **inp_array_2, int columns, int rows);
void out_matrix(double **result_matrix, int columns, int rows);
double **substraction(double **inp_array_1, double **inp_array_2, int columns, int rows);
double **transpose(double **inp_array, int columns, int rows);
double **composition(double **inp_array_1, double **inp_array_2, int columns_2, int rows_1, int columns_1, int rows_2);
int main(void) {
	char symb = 'o';
	printf_s("Welcome to matrix calculator!\n");
	while (symb != '0') {
		printf_s("\nWhat operation would you like to perform ? \n1.Matrix addition\n"
			"2.Matrix substraction\n3.Matrix transpose\n4.Matrix compostition\n0.Exit\n");
		do {
			scanf_s("%c", &symb, 1);
		} while (symb == '\n');
		if (symb == '1') {
			printf_s("Enter first file\n");
			struct inform_matrix s = find_size();
			double **inp_array_1 = get_matrix(s);
			out_matrix(inp_array_1,s.columns, s.rows);
			printf_s("\nEnter second file\n");
			struct inform_matrix t = find_size();
			double **inp_array_2 = get_matrix(t);
			out_matrix(inp_array_2,t.columns, t.rows);
			if (s.columns != t.columns || s.rows != t.rows) {
				printf_s("\nDifferent sizes of matrices");
				exit(1);
			}
			double **result_matrix = addition(inp_array_1, inp_array_2, s.columns, s.rows);
			printf_s("\nResult:\n");
			out_matrix(result_matrix,s.columns, s.rows);
			erase_matrix(inp_array_1, s.rows);
			erase_matrix(inp_array_2, t.rows);
			erase_matrix(result_matrix, s.rows);
		}
		if (symb == '2') {
			printf_s("Enter first file\n");
			struct inform_matrix s = find_size();
			double **inp_array_1 = get_matrix(s);
			out_matrix(inp_array_1, s.columns, s.rows);
			printf_s("Enter second file\n");
			struct inform_matrix t = find_size();
			double **inp_array_2 = get_matrix(t);
			out_matrix(inp_array_2, t.columns, t.rows);
			if (s.columns != t.columns || s.rows != t.rows) {
				printf_s("\nDifferent sizes of matrices");
				exit(1);
			}
			double **result_matrix = substraction(inp_array_1, inp_array_2, s.columns, s.rows);
			printf_s("\nResult:\n");
			out_matrix(result_matrix, s.columns, s.rows);
			erase_matrix(inp_array_1, s.rows);
			erase_matrix(inp_array_2, t.rows);
			erase_matrix(result_matrix, s.rows);
		}
		if (symb == '3') {
			printf_s("Enter file\n");
			struct inform_matrix s = find_size();
			double **inp_array = get_matrix(s);
			out_matrix(inp_array, s.columns, s.rows);
			double **result_matrix = transpose(inp_array, s.columns, s.rows);
			printf_s("\nResult:\n");
			out_matrix(result_matrix, s.rows, s.columns);
			erase_matrix(inp_array, s.rows);
			erase_matrix(result_matrix, s.rows);	
		}
		if (symb == '4') {
			printf_s("Enter first file\n");
			struct inform_matrix s = find_size();
			double **inp_array_1 = get_matrix(s);
			out_matrix(inp_array_1, s.columns, s.rows);
			printf_s("Enter second file\n");
			struct inform_matrix t = find_size();
			double **inp_array_2 = get_matrix(t);
			out_matrix(inp_array_2, t.columns, t.rows);
			double **result_matrix = composition(inp_array_1, inp_array_2, t.columns, s.rows, s.columns, t.rows);
			printf_s("\nResult:\n");
			out_matrix(result_matrix, t.columns, s.rows);
			erase_matrix(inp_array_1, s.rows);
			erase_matrix(inp_array_2, t.rows);
			erase_matrix(result_matrix, s.rows);
		}
		if (symb != '0' && symb != '1' && symb != '2' && symb != '3' && symb != '4') {
			printf_s("Wrong operation");
		}
	}
	return 0;
}
