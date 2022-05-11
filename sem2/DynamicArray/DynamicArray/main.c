#include <stdio.h>
#include <stdlib.h>

struct Dyn_Array {
	int* array;
	int size;
	int capacity;
};

typedef struct Dyn_Array dyn_array;

dyn_array* create(int capacity) {
	dyn_array* array = (dyn_array*)malloc(sizeof(dyn_array));
	array->size = 0;
	array->capacity = capacity;
	array->array = (int*)malloc(capacity * sizeof(int));
	return array;
}

void resize_array(dyn_array* d, int capacity) {
	int* new_array = (int*)realloc(d->array, capacity * sizeof(int));
	if (new_array) {
		d->array = new_array;
		d->capacity = capacity;
	}
	if (d->size > capacity) {
		d->size = capacity;
	}
}

void add(dyn_array* d, int number) {
	if (d->size == d->capacity) {
		resize_array(d, d->capacity * 2);
	}
	d->array[d->size] = number;
	d->size++;
}

int at(dyn_array* d, int index) {
	if (index >= 0 && index < d->size) {
		return d->array[index];
	}
	else {
		return 0;
	}
}

void remove_el(dyn_array* d, int index) {
	if (index >= 0 && index < d->size) {
		for (int i = index + 1; i < d->capacity; i++) {
			d->array[i - 1] = d->array[i];
		}
		d->size--;
	}
}

void removeAll(dyn_array* d) {
	d->size = 0;
}

void print(dyn_array* d) {
	for (int i = 0; i < d->size; ++i) printf("%d", d->array[i]);
	printf("\n");
}

int find_in_range(dyn_array* d, int number, int begin_ind, int end_ind) {
	if (begin_ind < 0 || begin_ind > d->size) begin_ind = 0;
	if (end_ind < 0 || end_ind > d->size) end_ind = d->size;

	for (int i = begin_ind; i < end_ind; ++i) {
		if (d->array[i] == number) return i;
	}
	return -1;
}

int find(dyn_array* d, int number) {
	return find_in_range(d, number, 0, d->size);
}

int count(dyn_array* d, int number) {
	int ind = -1;
	int count = -1;
	do {
		ind = find_in_range(d, number, ind + 1, d->size);
		count++;
	} while (ind != -1);
	return count;
}

int compare(int* number_1, int* number_2) {
	return *number_1 - *number_2;
}

int uniqe(dyn_array* d) {
	int counter = 0;
	for (int i = 0; i < d->size; i++) {
		if (count(d, d->array[i]) == 1) counter++;
	}
	return counter;
}

void sort_array(dyn_array* d) {
	qsort(d->array, d->size, sizeof(int), compare);
}

int main(int argc, char** argv) {
	dyn_array* d = create(4);
	add(d, 5);
	add(d, 3);
	add(d, 2);
	add(d, 1);
	add(d, 1);
	add(d, 1);
	int a = at(d, 3);
	printf_s("%d\n", a);
	print(d);
	remove_el(d, 3);
	print(d);
	int un = uniqe(d);
	printf_s("%d\n", un);
	sort_array(d);
	print(d);
	return 0;
}