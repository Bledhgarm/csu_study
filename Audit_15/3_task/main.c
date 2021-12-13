#include "chess.h" 

int main(void) {
	int desk[ROWS][COLUMNS];
    char pos[SIZELINE];
	getting_str(pos);
    preparation(desk, pos);
	printing_desk(desk);
	diagonal_check(desk);
	line_check(desk);
	printf("It's right\n");


}
