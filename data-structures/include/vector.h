#ifndef _VECTOR_H
#define _VECTOR_H

#include <stddef.h>

typedef struct {
    size_t capacity;
    size_t size;
    int *arr;
} vector;

vector * newVector(void);

void freeVector(vector *vector);

void pushVector(vector *vector, int value);

void printVector(vector *vector);

#endif