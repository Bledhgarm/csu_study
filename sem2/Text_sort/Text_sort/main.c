#include <stdio.h>
#include <string.h>
#include <locale.h> 
#include <stdlib.h>

int compare(const void* first, const void* second);

int main(int argc, char** argv) {
	setlocale(0, "Russian");
	FILE* book = NULL;
	char symb = '0';
	int counter = 0;
	int str_counter = 0;
	int* tmp_array = NULL;
	int* book_array_counter = NULL;
	fopen_s(&book, "book.txt", "r");
	if (book == NULL) {
		perror("Fail on opening file");
		system("pause");
		return 1;
	}
	while (!feof(book)) {
		symb = fgetc(book);
		str_counter++;
		if (symb == '\n') {
			counter++;
			tmp_array = (int*)realloc(book_array_counter, counter * sizeof(int));
			if (tmp_array != NULL) {
				book_array_counter = tmp_array;
				book_array_counter[counter - 1] = str_counter;
				str_counter = 0;
			}
			else {
				free(book_array_counter);
				free(tmp_array);
			}
		}
		else if (symb == '\0') break;
	}
	rewind(book);
	char** text = (char**)malloc(counter * sizeof(char*)); 
	for (int i = 0; i < counter; i++) {
		text[i] = (char*)malloc(book_array_counter[i] * sizeof(char));
		for (int j = 0; j < book_array_counter[i]; j++) {
			text[i][j] = fgetc(book);
		}
	}
	qsort(text, counter, sizeof(char*), compare);
	fclose(book);
	free(book_array_counter);
	for (int i = 0; i < counter; i++) {
		for (int j = 0; text[i][j] != '\n'; j++) {
			printf("%c", text[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < counter; i++) {
		free(text[i]);
	}
	free(text);

	return 0;
}

int compare(const void* first, const void* second) {
	const char** tmp_1 = (char**)first;
	const char** tmp_2 = (char**)second;
	return (strlen(*tmp_1) - strlen(*tmp_2));
}