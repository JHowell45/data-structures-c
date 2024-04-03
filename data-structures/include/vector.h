#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    size_t capacity;
    size_t size;
    int *arr;
} vector;

void vector_init(vector *v, size_t capacity);

vector * new_vec(size_t capacity);

void vector_push(vector *v, int data);

void vector_pop(vector *v);

int vector_get(vector* v, size_t index);

int vector_index_of(vector *v, int searchValue);

void vector_insert(vector *v, size_t index, int data);

void vector_delete(vector *v, size_t index);

void vector_destroy(vector *v);

void vector_print(vector *v);

#endif