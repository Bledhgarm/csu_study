#include <stdio.h>

int main(int argc, char *argv[]) {
	int A = atoi(argv[0]);
	int B = atoi(argv[1]);
	int C = atoi(argv[2]);
	FILE *f = argv[3];

	fopen_s(&f, "task.txt", "r");

	return 0;
}
