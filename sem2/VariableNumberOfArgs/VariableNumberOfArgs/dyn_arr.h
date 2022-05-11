#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Dyn_Array {
	const char** array;
	int size;
	int capacity;
};

typedef struct Dyn_Array dyn_array;

dyn_array* create(int capacity) {
	dyn_array* array = (dyn_array*)malloc(sizeof(dyn_array));
	array->size = 0;
	array->capacity = capacity;
	array->array = (const char**)malloc(capacity * sizeof(const char*));
	return array;
}

void resize_array(dyn_array* d, int capacity) {
	const char** new_array = (const char**)realloc(d->array, capacity * sizeof(const char*));
	if (new_array) {
		d->array = new_array;
		d->capacity = capacity;
	}
	if (d->size > capacity) {
		d->size = capacity;
	}
}

void add(dyn_array* d, const char* str) {
	if (d->size == d->capacity) {
		resize_array(d, d->capacity * 2);
	}
	d->array[d->size] = str;
	d->size++;
}

const char* at(dyn_array* d, int index) {
	if (index >= 0 && index < d->size) {
		return d->array[index];
	}
	else {
		return 0;
	}
}
