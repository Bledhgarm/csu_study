#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	int counter = 0;
	int len_list[100] = { 0 };
	int index[100] = { 0 };
	char *list_words[100] = { 0 };
	for (int i = 0; i < argc - 2; i++) {
		index[i] = i;
	}
	for (int i = 0; i < argc - 2; i++) {
		len_list[i] = strlen(argv[i+2]);
	}
	for (int i = 0; i < argc - 2; i++) {
		for (int j = 0; j < argc - 3; j++) {
			if (len_list[j] < len_list[j + 1]) {
				int tmp = len_list[j];
				len_list[j] = len_list[j + 1];
				len_list[j + 1] = tmp;
				int tmp_2 = index[j];
				index[j] = index[j + 1];
				index[j + 1] = tmp_2;
			}
		}
	}
	for (int i = 0; i < atoi(argv[1]); i++) {
		list_words[i] = argv[index[i] + 2];
		counter++;
	}
	for (int j = 0; j < argc - 2; j++) {
		for (int k = 0; k < counter; k++) {
			if (argv[j + 2] == list_words[k]) {
				printf("%s ", argv[j + 2]);
			}
		}	
	}
	putchar('\n');
	return 0;
}
