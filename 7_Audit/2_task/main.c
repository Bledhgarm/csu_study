#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	char **str_arr = (char **)malloc(N * sizeof(char *));
	for (int i = 0; i < N; i++) {
		str_arr[i] = (char *)malloc((M + 1) * sizeof(char));
		gets(str_arr[i]);
	}
	for (int i = 0; i < N; i++) {
		if (strlen(str_arr[i]) < 5) {
			for (int j = 0; j < strlen(str_arr[i]) - 2; j++) {
				char tmp = str_arr[i][j];
				str_arr[i][j] = str_arr[i][strlen(str_arr[i]) - 1 - j];
				str_arr[i][strlen(str_arr[i]) - 1 - j] = tmp;
			}
		}
		else {
			for (int j = 0; j < strlen(str_arr[i]) - 3; j++) {
				char tmp = str_arr[i][j];
				str_arr[i][j] = str_arr[i][strlen(str_arr[i]) - 1 - j];
				str_arr[i][strlen(str_arr[i]) - 1 - j] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (strlen(str_arr[i]) > M) {
			printf_s("%s - Is Too Big String\n", str_arr[i]);
			continue;
		}
		else if (str_arr[i] != NULL || strlen(str_arr[i] <= M)) {
			printf_s("%s (len = %d)\n", str_arr[i], strlen(str_arr[i]));
		}
		free(str_arr[i]);
	}
	free(str_arr);
	return 0;
}
