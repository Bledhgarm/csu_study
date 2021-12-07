#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
struct values {
	int N_number;
	int E_number;
	int S_number;
	int W_number;
};

struct sides {
	char N;
	char E;
	char S;
	char W;
	struct values v;
};
int main(int argc, char **argv) {
	struct sides s;
	int number;
	char *tmp = (char *)malloc(256 * sizeof(char));
	for (int i = 0; i < strlen(argv[1]); i++) {
		char symb = argv[1][i]; 
		if (symb > '0' || symb < '9') {
			strcat(tmp, symb);
		}
		else {
			switch (symb) {
				case 'N':
					s.v.N_number += atoi(tmp);
				case 'E':
					s.v.E_number += atoi(tmp);
				case 'S':
					s.v.S_number += atoi(tmp);
				case 'W':
					s.v.W_number += atoi(tmp);
			}
		}
	}
	free(tmp); 
	return 0;
}