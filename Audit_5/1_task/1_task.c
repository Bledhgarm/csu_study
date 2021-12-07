#include <stdio.h>

#define MAX_ARRAY_SIZE 100
#define INPUT_FILE_NAME "numbers"
#define OUTPUT_FILE_NAME "sorted"

void sort(int[MAX_ARRAY_SIZE]);

int main(void) {
    FILE *input, *output;
    int arr[MAX_ARRAY_SIZE] = { 0 };

    if (fopen_s(&input, "numbers.txt", "r")) {
        printf_s("ERROR");
        _fcloseall();
        exit(1);
    }
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        fscanf_s(input, "%d", &arr[i]);
        printf_s("%d ", arr[i]);
    }
    
    sort(arr);
    fopen_s(&output, "sorted.txt", "w");
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        fprintf_s(output, "%d ", arr[i]);
    }

    fclose(input);
    fclose(output);
    return 0;
}

void sort(int arr[MAX_ARRAY_SIZE]) {
    for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
        for (int i = 1; i < MAX_ARRAY_SIZE; ++i) {
            if (arr[i] < arr[i - 1]) {
                int tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
            }
        }
    }
}