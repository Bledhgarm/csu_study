#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLUMNS 8
#define SIZELINE 17
void getting_str(char line[]);
void preparation(int desk[ROWS][COLUMNS],char pos[]);
void reflectiongorizontal(int desk[ROWS][COLUMNS]); 
void printing_desk(int desk[ROWS][COLUMNS]);
void diagonal_check(int desk[ROWS][COLUMNS]);
void line_check(int desk[ROWS][COLUMNS]);

