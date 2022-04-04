#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	char text[100] = { 0 };
	char *main_str = argv[1];
	char *alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNPQRSTUVWXYZ";
	while (true) {
		printf("\nEnter a string: \n");
		int result = 0;
		int counter[52] = { 0 };
		for (int i = 0; i < strlen(main_str); i++) {
			for (int j = 0; j < strlen(alph); j++) {
				if (alph[j] == main_str[i])
					counter[j]++;
			}
		}

		gets(text);
		if (text[0] == '\0')
			break;
		for (int i = 0; i < strlen(text); i++) {
			for (int j = 0; j < strlen(alph); j++) {
				if (text[i] == alph[j]) {
					counter[j]--;
					if (counter[j] < 0) {
						result++;
						printf("false\n");
						break;
					}
				}
			}
			if (result > 0)
				break;
		}
		if (result == 0) {
			printf("true\n");
		}
	}
	return 0;
}
