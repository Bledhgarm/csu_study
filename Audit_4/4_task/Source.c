#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100
void bubble(int *array, int size);
void unite(int *final_array, int *dig_n, int *other);
void printing(int *array, int size);

int main() {
    int arr[ARRAY_SIZE];
    unsigned int counter = 0;
    unsigned int n;
    scanf_s("%d", &n);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = (rand() % 2 ? -1 : 1) * (rand() % 100);
        if (arr[i] % n == 0) {
            counter++;
        }
    }
    int *dig_n = (int *)malloc(counter * sizeof(int));
    int *other = (int *)malloc((ARRAY_SIZE - counter) * sizeof(int));
    int *final_array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    int size_dig = counter;
    int size_other = ARRAY_SIZE-counter;
    for (int i = 0, j = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] % n == 0) {
            dig_n[j] = arr[i];
            j++;
        }
    }
    for (int j = 0, k = 0; j < ARRAY_SIZE; j++) {
        if (k < ARRAY_SIZE - counter) {
            if (arr[j] % n != 0) {
                other[k] = arr[j];
                k++;
            }
        }
    }
    bubble(dig_n, size_dig);
    bubble(other, size_other);
    unite(final_array, dig_n, other);
    printing(dig_n, size_dig);
    printf_s("\n");
    printing(other, size_other);
    printf_s("\n");
    printing(final_array, ARRAY_SIZE);
    free(dig_n);
    free(other);
    free(final_array);
    return 0;
}


void bubble(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}


void unite(int *final_array,int *dig_n, int *other) {
    for (int i = 0, j = 0, k = 0; i < ARRAY_SIZE; i++) {
        if (other[j] < dig_n[k]) {
            final_array[i] = dig_n[k];
            k++;
        }
        else {
            final_array[i] = other[j];
            j++;
        }
    }
}

void printing(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf_s("%d ", array[i]);
    }
}
