#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fname;
	int lines_counter = 0;
	char symb;
	int counter_symb = 0;
	if (fopen_s(&fname, argv[1], "r")) {
		return 1;
	}
	else {
		while (fscanf_s(fname, "%c", &symb, 1) != EOF) {
			counter_symb;
		}
		while (!feof(fname)) {
			if (fgetc(fname) == '\n')
				lines_counter++;
		}
		lines_counter++;
		char *array = (char *)malloc(lines_counter * sizeof(char));
		for (int i = 0; i < lines_counter; i++) {
			fgets(array[i], 100, fname);
		}
	}
	fclose(fname);
	fopen_s(&fname, argv[1], "w+");
	fseek(fname, 0, SEEK_SET);
	fprintf_s(fname, "%d", lines_counter);
	for (int i = 0; i < lines_counter; i++) {
		fprintf_s(fname, "%s", array[i]);
	}
	printf_s("%d", lines_counter);
	fclose(fname);
	return 0;
}