#include "parsing.h"

int parsingParam(int argc, char** argv, struct config* conf) {
	conf->m1 = conf->m2 = conf->n = -1;
	conf->a = conf->C = NULL;
	conf->c = 0;
	for (int i = 1; i < argc; i++) {
		char* current = argv[i];
		int sign;
		int done = 0;
		for (int j = 0; j < 5; j++) {
			if (strcmp(current, conf->possibleOptions[j]) == 0) {
				switch (j) {
				case 0:
					done = 1;
					if (conf->m1 != -1) {
						if (isInteger(argv[i + 1])) i++;
						break;
					}
					if ((i + 1) < argc) conf->m1 = atoi(argv[i + 1]);
					else return error("No argument for -m1\n");
					if (errno != 0 || !isInteger(argv[i + 1]) || conf->m1 < 0) return error("Wrong option -m1\n");
					i++;
					break;
				case 1:
					done = 1;
					if (conf->m2 != -1) {
						if (isInteger(argv[i + 1])) i++;
						break;
					}
					if ((i + 1) < argc) conf->m2 = atoi(argv[i + 1]);
					else return error("No argument for -m2\n");
					if (errno != 0 || !isInteger(argv[i + 1]) || conf->m2 <= 0) return error("Wrong option -m2\n");
					i++;
					break;
				case 2:
					done = 1;
					if (conf->n != -1) {
						if (isInteger(argv[i + 1])) i++;
						break;
					}
					if ((i + 1) < argc) conf->n = atoi(argv[i + 1]);
					else return error("No argument for -n\n");
					if (errno != 0 || !isInteger(argv[i + 1]) || conf->n <= 0) return error("Wrong option -n\n");
					i++;
					break;
				case 3:
					done = 1;
					if (conf->c != 0) {
						if (isInteger(argv[i + 1])) i++;
						break;
					}
					if ((i + 1) < argc) conf->c = atoi(argv[i + 1]);
					else return error("No argument for -c\n");
					if (errno != 0 || !isInteger(argv[i + 1]) || conf->c <= 0) return error("Wrong option -c\n");
					i++;
					break;
				case 4:
					done = 1;
					if (conf->a != NULL && conf->alph != NULL) {
						if (isInteger(argv[i + 1])) i++;
						break;
					}
					if ((i + 1) < argc) conf->alph = conf->a = argv[i + 1];
					else return error("No argument for -a\n");
					i++;
					break;
				}
			}
		}
		if (done == 0) {
			if (current[0] == '-' && current[1] == 'C') {
				if (conf->C != NULL) continue;
				if (strlen(current) == 2) return error("Wrong option -C\n");

				size_t maxLength = strlen(conf->digits) + strlen(conf->lowerCase) + strlen(conf->upperCase) + strlen(conf->specialChars) + 1;
				conf->C = calloc(maxLength, sizeof(char));
				int flaga, flagA, flagS, flagD;
				flaga = flagA = flagS = flagD = 0;
				for (int k = 2; k < strlen(current); k++) {
					char* ptr = NULL;
					switch (current[k]) {
					case 'a':
						if (flaga == 0) {
							ptr = conf->lowerCase;
							flaga = 1;
						}
						break;
					case 'A':
						if (flagA == 0) {
							ptr = conf->upperCase;
							flagA = 1;
						}
						break;
					case 'D':
						if (flagD == 0) {
							ptr = conf->digits;
							flagD = 1;
						}
						break;
					case 'S':
						if (flagS == 0) {
							ptr = conf->specialChars;
							flagS = 1;
						}
						break;
					default:
						return error("Wrong option -C\n");
					}
					if (ptr != NULL) {
						strcpy_s(conf->C + strlen(conf->C), (maxLength - strlen(conf->C)) * sizeof(char), ptr);
					}
				}
				conf->alph = conf->C;
			}
			else printf("Skipped unknown option: %s\n", current);
		}
	}
	if (conf->n != -1 &&
		(conf->m1 != -1 || conf->m2 != -1)) {
		return error("Options m1, m2 and n can't be used simultaneously!\n");
	}
	if (conf->n == -1 &&
		(conf->m1 == -1 || conf->m2 == -1)) {
		return error("No length for password!\n");
	}
	if (conf->m1 != -1 && conf->m2 == -1 ||
		conf->m1 == -1 && conf->m2 != -1) {
		return error("Only one mX option was found!\n");
	}
	if (conf->m1 > conf->m2) {
		return error("m1 value greater than m2!\n");
	}
	if (conf->a != NULL && conf->C != NULL) {
		return error("Options a and C can't be used simultaneously!\n");
	}
	if (conf->a == NULL && conf->C == NULL) {
		return error("Option a or C is required!\n");
	}
	if (conf->c == 0) conf->c = 1;
	return 0;
}

int error(char* str) {
	printf("Error\n%s", str);
	return 1;
}