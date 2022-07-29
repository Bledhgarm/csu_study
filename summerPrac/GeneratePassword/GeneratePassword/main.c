#include "config.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>



void tests(struct config conf);

int main(int argc, char** argv) {
	struct config conf;
	srand(time(NULL));
	char* possibleOptions[] = { "-m1","-m2", "-n", "-c", "-a" };
	conf.possibleOptions = possibleOptions;
	conf.digits = "0123456789";
	conf.lowerCase = "qwertyuiopasdfghjklzxcvbnm";
	conf.upperCase = "QWERTYUIOPASDFGHJKLZXCVBNM";
	conf.specialChars = " ~!@#$%^&*()-_=+\\|,./<>?;:'\"[{]}`";
	//tests(conf);
	if (parsingParam(argc, argv, &conf) == 0) {
		generatePassword(&conf);
	}
	return 0;
}




void tests(struct config conf) {
#define str(S) #S
#define STR(S) str(S)
#define arg(TEST) arg ## TEST
#define ARG(TEST) arg(TEST)

#define TEST_NAME test1
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-m1", "5", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	int check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test2
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m1", "5", "-n", "10", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test3
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m2", "5", "-n", "10", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test4
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m1", "5", "-m2", "10", "-n", "15", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test5
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m1", "5", "-m2", "10", "-m2", "15", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0 &&
		conf.m1 == 5 && conf.m2 == 10 && strcmp(conf.alph, "a") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test6
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m1", "5", "-m1", "10", "-m2", "15", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0 &&
		conf.m1 == 5 && conf.m2 == 15 && strcmp(conf.alph, "a") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test7
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-CS", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test8
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-m1", "10", "-m2", "5", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test9
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "0", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test10
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-C" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test11
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test12
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test13
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m1", "0", "-m2", "0", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test14
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "0", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test15
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "5", "-n", "10", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0 &&
		conf.n == 5 && conf.c == 1 && strcmp(conf.alph, "a") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test16
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-m1", "10", "-m2", "10", "-c", "-1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test17
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "-1", "-c", "1", "-a", "a" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test18
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-Ca" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, conf.lowerCase) == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test19
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-CA" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, conf.upperCase) == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test20
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-CD" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, conf.digits) == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test21
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-CS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, conf.specialChars) == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test22
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-n", "10", "-c", "1", "-CaADS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789 ~!@#$%^&*()-_=+\\|,./<>?;:'\"[{]}`") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test23
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "","-n", "10", "-c", "1", "-CaA" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test24
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-n", "10", "-c", "1", "-CDS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, "0123456789 ~!@#$%^&*()-_=+\\|,./<>?;:'\"[{]}`") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test25
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-n", "10", "-c", "1", "-CaS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, "qwertyuiopasdfghjklzxcvbnm ~!@#$%^&*()-_=+\\|,./<>?;:'\"[{]}`") == 0);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test26
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-n", "10", "-c", "1" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test27
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-n", "-c", "1", "-CaS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test28
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-m1", "10", "-m2", "-c", "1", "-CaS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test29
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-m1", "-m2", "10", "-c", "1", "-CaS" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 1);
	if (check == 0) generatePassword(&conf);

#define TEST_NAME test30
	printf("TEST %s\n", STR(TEST_NAME));
	char* TEST_NAME[] = { "", "-n", "10", "-X", "-D", "-a", "a", "-qwerty" };
	int ARG(TEST_NAME) = sizeof(TEST_NAME) / sizeof(char*);
	check = parsingParam(ARG(TEST_NAME), TEST_NAME, &conf);
	assert(check == 0
		&& conf.n == 10 && conf.c == 1 && strcmp(conf.alph, "a") == 0);
	if (check == 0) generatePassword(&conf);

	//assert(parsingParam(argc1, test1, &conf) == 0 &&
	//	conf.m1 == 5 && conf.m2 == 10 && conf.c == 5 && strcmp(conf.a, "qwerty") == 0);
	//assert(parsing_param(argc2, test2, &conf) == 0 &&
	//	conf.m1 == 5 && conf.m2 == 10 && conf.c == 5 && strcmp(conf.a, "qwerty") == 0);
	//parsingParam(argc2, test2, &conf);
	//printf("-a %s", conf.a);

}