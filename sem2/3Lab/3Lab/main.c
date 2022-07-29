#include "str.h"

int main(void) {
    printf("If you wanna exit press 0\n");
    while (1) {
        printf("Enter your string\n");
        char* str = (char*)malloc(SIZESTR * sizeof(char));
        fgets(str, SIZESTR, stdin);
        if (*str == '0')
            break;
        printf("For finding substring in string enter your pattern\n");
        char* pattern = (char*)malloc(SIZESTR * sizeof(char));
        fgets(pattern, SIZESTR, stdin);
        printf("%s\n", str_replace(str, pattern));
        /*   	        if (index >= 0)
                        printf("\nCount of pattern in string: %d\n", number_enter(str, pattern));
                    else
                        printf("\nThere is no pattern in this string\n"); */
        free(pattern);
        free(str);
    }

    return 0;
}

