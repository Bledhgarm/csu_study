#include <stdio.h>

int main(void) {
	int counter = 0; 
	int number = 0;
	FILE *input;
	fopen_s(&input, "tests.txt", "r");
	while (fscanf_s(input, "%d", &number) != EOF) {
		counter++;
	}
	
	fclose(input);
	return 0;
}