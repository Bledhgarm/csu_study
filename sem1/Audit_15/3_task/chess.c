#include "chess.h"

void getting_str(char line[]) {
	char s;
	int size = 0;
	for (size = 0; (size < SIZELINE - 1) && (s = getchar()) != EOF && (s != '\n'); size++) {
		line[size] = s;
	}
	if (s == '\n') {
		line[size] = '\n';
		size++;
	}
	line[size] = '\0';

}
void preparation(int desk[ROWS][COLUMNS],char pos[]) {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++) {
			desk[i][j] = 0;
		}
    int k = 0;
	for (int i = 0; i < 8; i++) {
		desk[pos[i * k] - 49][pos[i * k + 1] - 49] = 1;
		k = 2;
	}
}
void reflectiongorizontal(int desk[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS / 2; j++) {
			int tmp = desk[i][j];
			desk[i][j] = desk[i][COLUMNS - 1 - j];
			desk[i][COLUMNS - 1 - j] = tmp;
		}
	}
}
void printing_desk(int desk[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			printf("%d ", desk[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void diagonal_check(int desk[ROWS][COLUMNS]) {
	static int counter = 0;
	for (int k = 1; k < 8; k++) {
		int sum = 0;
		for (int i = k, j = 0; ; i--, j++) {
			sum += desk[i][j];
			if (i == 0) break;
		}
		if (sum > 1) {
			printf("the placement is incorrect\n");
			exit(1);
		}
	}

	for (int q = 1; q < 7; q++) {
		int sum = 0;
		for (int i = 7, j = q; ; i--, j++) {
			sum += desk[i][j];
			if (i == 7) break;
		}
		if (sum > 1) {
			printf("the placement is incorrect\n");
			exit(1);
		}
	}

	
	counter++;
	if (counter > 1) return;
	reflectiongorizontal(desk);
	diagonal_check(desk);
}
void line_check(int desk[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		int sum = 0;
		for (int j = 0; j < COLUMNS; j++) {         
			sum += desk[i][j];
		}
		if (sum > 1) {
			printf("the placement is incorrect\n");
			exit(1);
		}
	}
	for (int j = 0; j < ROWS; j++) {
		int sum = 0;
		for (int i = 0; i < COLUMNS; i++) {        
			sum += desk[i][j];
		}
		if (sum > 1) {
			printf("the placement is incorrect\n");
			exit(1);
		}
	}
	return;
}
