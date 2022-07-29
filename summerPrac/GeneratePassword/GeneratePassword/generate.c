#include "generate.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}
int isInteger(char* str) {
	if (*str == '-') str++;
	while (*str != '\0') {
		if (!isDigit(*str)) return 0;
		str++;
	}
	return 1;
}

void generatePassword(struct config* conf) {
	for (int i = 0; i < conf->c; i++) {
		int lengthPassword = getPasswordLength(conf);
		char* password = calloc(lengthPassword + 1, sizeof(char));
		for (int j = 0; j < lengthPassword; j++) {
			password[j] = conf->alph[rand() % strlen(conf->alph)];
		}
		printf("%s\n", password);
		free(password);
	}
}

int getPasswordLength(struct config* conf) {
	if (conf->m1 != -1) return conf->m1 + rand() % (conf->m2 - conf->m1 + 1);
	else return conf->n;
}