#include <stdio.h>
#include <windows.h> 
#define HEIGHT 9
#define WEIGHT 19

int main(void) {
	
	for (int i = 0; i <= HEIGHT; i++) {
		if ((i == 0) || (i == 9)) {
			for (int j = 0; j <= WEIGHT; j++) {
				putchar('-');
				Sleep(100);
			}
			printf_s("\n");
			
		}
		else {
			putchar('|');
			for (int k = 1; k <= WEIGHT; k++) {
				putchar(' ');
				
			}
			putchar('|');
			Sleep(100);
				
			
			
		printf_s("\n");
		}
	}
	return 0;
}