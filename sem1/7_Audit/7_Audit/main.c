#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int N, M;
	scanf_s("%d", &N);
	scanf_s("%d ", &M);
	char **str_arr = (char **)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) {
		str_arr[i] = (char *)malloc((M + 1) * sizeof(char));
		gets(str_arr[i]);
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