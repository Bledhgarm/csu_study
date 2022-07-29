#include "strOperations.h"
void tests(void);

int strtoi(const char* str, char** p, int* ret);
int my_itoa(char* buf, int bufSize, int value, int p);
int newSizeBuf(int value, int p);
char getDigitGiveSymb(int value, int p);
int absolute(int value);
int getNumberBase(const char** p);
int charToNum(char c, int* result);
int addChecked(int a, int b, int* r);
int subChecked(int a, int b, int* r);

int main() {
	//tests();
	char* error = 0;
	int number = 0;
	int status = strtoi("0xFFFFFFFF", NULL, &number);

	if (status)
		printf("Result: %d\n\n", number);
	else {
		if (error != 0)
			printf("Error: %s\n\n", error);
		else
			printf("Error.\n\n");
	}

	int bufSize = 100;
	char* buf1 = calloc(bufSize, 0);
	int value = 12345;
	int p = 10;
	my_itoa(buf1, bufSize, value, p);
	printf("%s\n\n", buf1);
	return 0;

}

void tests(void) {
	// newSizeBuf
	assert(newSizeBuf(1, 10) == 1);
	assert(newSizeBuf(1, 2) == 1);
	assert(newSizeBuf(10, 10) == 2);
	assert(newSizeBuf(8, 2) == 4);
	assert(newSizeBuf(16, 16) == 2);
	assert(newSizeBuf(15, 16) == 1);
	assert(getDigitGiveSymb(10, 16));
	int bufSize = 100;
	char* buf = calloc(bufSize, 1);
	int value = 12345;
	int p = 10;

	//assert(5 == my_itoa(buf, bufSize, -9, 2));
	//assert(!strcmp(buf, "-1001"));

	//printf("%s\n", buf);
	// test for radix 10
	int radix = 10;
	for (int i = INT_MIN; i < INT_MAX - 10000; i += rand() % 10000) {
		char buf1[100] = { 0 };
		char buf2[100] = { 0 };
		int characters = my_itoa(buf1, 100, i, radix);
		sprintf_s(buf2, 100, "%d", i);
		/*	printf("%d\t=>\t%s\tcharacters: %d\n", i, buf1, characters);*/
		assert(!strcmp(buf1, buf2));
		assert(characters == newSizeBuf(i, radix));
		int number;
		strtoi(buf1, NULL, &number);
		assert(i == number);
	}

	// test for radix 16
	radix = 16;
	for (int i = INT_MIN; i < INT_MAX - 10000; i += rand() % 10000) {
		int sign = i < 0 ? 1 : 0;
		char buf1[100] = { 0 };
		char buf2[100] = { 0 };
		int characters = my_itoa(buf1 + 2, 100, i, radix);
		sprintf_s(buf2, 100, "%X", i < 0 ? -i : i);
		buf1[0] = sign ? '-' : '0';
		buf1[1] = sign ? '0' : 'x';
		buf1[2] = sign ? 'x' : buf1[2];
		//printf("%s%s\t=>\t%s\tcharacters: %d\n", i < 0 ? "-" : "", buf2, buf1, characters);
		assert(!strcmp(buf1 + 2 + sign, buf2));
		assert(characters == newSizeBuf(i, radix));
		int number;
		strtoi(buf1, NULL, &number);
		assert(i == number);
	}

	int numbers[] = { 0, 10, -1, -10, 12345, -12345, INT_MIN, INT_MAX };
	int answers[] = { 1, 2, 2, 3, 5, 6, 11, 10 };
	for (int i = 0; i < sizeof(numbers) / sizeof(*numbers); ++i) {
		printf("number: %d, got counter: %d\n", numbers[i], my_itoa(NULL, 0, numbers[i], 10));
		assert(my_itoa(NULL, 0, numbers[i], 10) == answers[i]);
	}
	
}

