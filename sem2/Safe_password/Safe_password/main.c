#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include <stdio.h>
#include <string.h>

int main() {
	int pass_len = 0;
	int punct = 0;
	int upp = 0;
	int low = 0;
	int result = 0;
	char symb;
	printf("Enter the length of your password\n");
	scanf_s("%d", &pass_len);
	char* password = (char*)malloc((pass_len + 1) * sizeof(char));
	for (int i = 0; i < pass_len; ++i) password[i] = 0;
	printf("Enter password\n");
	for (int i = 0; i < pass_len; i++)
	{
		symb = _getch();
		if (symb == 13) {
			break;
		}
		if (symb == 8) {
			_putch('\b'); _putch(' ');  _putch('\b');
			if (i >= 0) i = i - 2;
		}
		else {
			password[i] = symb;
			_putch('*');
		}
	}
	password[pass_len] = '\0';
	for (int i = 0; i < pass_len && (!punct && !upp && !low); i++) {
		if (!punct) punct = ispunct(password[i]);
		if (!upp) upp = isupper(password[i]);
		if (!low) low = isupper(password[i]);
	}
	result = punct + upp + low;
	if (result < 3) printf("\nYour password is very weak\n");
	else if (result == 3) printf("\nYour password has medium difficulty level\n");
	else printf("\nYour password if very strong\n");	
	return 0;
}