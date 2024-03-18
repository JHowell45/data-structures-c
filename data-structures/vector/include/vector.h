#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct vector_s vector;

typedef struct vector_s {
    size_t capacity;
    size_t size;
    int *arr;
} vector;

void vector_init(vector *v, size_t capacity);

void new_vec(size_t capacity);

void vector_push(vector *v, int data);

void vector_pop(vector *v);

int vector_get(vector* v, size_t index);

void vector_insert(vector *v, size_t index, int data);

void vector_delete(vector *v, size_t index);

void vector_destroy(vector *v);

#endif