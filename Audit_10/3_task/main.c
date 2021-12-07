#include <stdio.h>
#include <Windows.h>


//не работает с табул€цией
void myIsspace(char str[])
{
	FILE *output;
	fopen_s(&output, "out1.txt", "w");
	int i = 0, check = 1;
	while (str[i])
	{
		if (str[i] == ' ') {
			check = 1;
		}
		else {
			if ((str[i] == '.')  (str[i] == ',')  (str[i] == '!') || (str[i] == '?'))
			{
				fprintf(output, "%c", str[i]);
				check = 1;
			}
			else
			{
				if (check && i) {
					fprintf(output, " ", str[i]);
				}
				fprintf(output, "%c", str[i]);
				check = 0;
			}
		}
		i++;
	}
	fclose(output);
}

void myIsupper(char str[]) {
	FILE *output;
	fopen_s(&output, "out2.txt", "w");
	int i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] += 'A' - 'a';
			fprintf(output, "%c", str[i]);
		}
		else {
			if ('A' <= str[i] && str[i] <= 'Z') {
				str[i] -= 'A' - 'a';
				fprintf(output, "%c", str[i]);
			}
			else {
				fprintf(output, "%c", str[i]);
			}
		}
		i++;
	}
	fclose(output);
}


int main() {
	char buffer[1000] = { 0 };
	int lines_counter = 0;
	FILE *input;
	FILE *output;
	if (fopen_s(&input, "3.txt", "r")) {
		return  1;
	}
	else {
		fgets(buffer, 1000, input);
	}
	fclose(input);
	if (fopen_s())
		myIsupper(buf);
		myIsspace(buf);
	
}