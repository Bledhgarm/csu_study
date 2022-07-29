#include "str.h"

int my_strcmp(char* str, char* pattern) {
    for (; *str == *pattern; str++, pattern++) {
        if (*str == '\0')
            return 0;
    }
    return *str - *pattern;
}

int myn_strcmp(char* str, char* pattern, int counter) {
    for (int i = 0; i < counter; i++) {
        if (*str != *pattern) {
            return *str - *pattern;
        }
        str++;
        pattern++;
    }
    return 0;

}

int my_strlen(char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int number_enter(char* str, char* pattern) {
    int counter = 0;
    int index = find(str, pattern);
    while (index >= 0) {
        if (find(str, pattern) == -1) {
            break;
        }
        index = find(str, pattern);
        index += my_strlen(pattern);
        str += index;
        counter++;
    }
    return counter;
}

int find(char* str, char* pattern) {
    char* str_begin = str;
    char* pattern_begin = pattern;
    while (*str != '\0') {
        if (*str == *pattern) {
            if (myn_strcmp(str, pattern, my_strlen(pattern)) == 0) {
                return str - str_begin;
            }
            else {
                pattern = pattern_begin;
                str++;
            }
        }
        else str++;
    }
    return -1;
}
char* str_replace(char* str, char* pattern) {
    int index = find(str, pattern);
    str += index;
    printf("Enter your string for replace\n");
    char* new_pattern = (char*)malloc(SIZESTR * sizeof(char));
    fgets(new_pattern, SIZESTR, stdin);
    new_pattern[my_strlen(new_pattern) - 1] = '\0';
    if (index >= 0) {
        for (int i = 0; i < my_strlen(new_pattern); i++) {
            str[i] = new_pattern[i];
        }
        str -= index;
    
        /*        else {

                for (int i = 0; i < my_strlen(pattern); i++) {
                    str[i] = new_pattern[i];
                }
            } */
    }
    free(new_pattern);
    return str;
}



