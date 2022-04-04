#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	HKEY R;
	DWORD Value = 1;
	DWORD cBuff = 4;
	char* path = TEXT("Count");
	if (RegCreateKeyEx(HKEY_CURRENT_USER, path, NULL, NULL, 0x00000001L, KEY_ALL_ACCESS, NULL, &R, NULL) == ERROR_SUCCESS) {
		printf("Program started.\n"); 
		if (RegQueryValueEx(R, path, NULL, NULL, &Value, &cBuff) == ERROR_SUCCESS) {
			Value++;
			if (Value > 3) printf("Number of launches more then 3, trial period ended\n your lunchers is: %d\n", Value);
			else printf("This program has been run %d times\n", Value);
			RegSetValueEx(R, path, NULL, REG_DWORD, &Value, 4);
		}
		else {
			RegSetValueEx(R, path, NULL, REG_DWORD, &Value, 4);
			printf("This program has been run %d times\n", Value);
		}
	}
	system("pause");
	return 0;
}