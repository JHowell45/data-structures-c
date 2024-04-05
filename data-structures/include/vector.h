#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t capacity;
    size_t size;
    int *items;
} vector;

vector * newVector(void);

void freeVector(vector *vector);

void pushVector(vector *vector, int value);

void insertVector(vector *vector, int value, size_t index);

void popVector(vector *vector);

void removeVector(vector *vector, size_t index);

void clearVector(vector *vector);

int indexOfVector(vector *vector, int search);

bool isEmptyVector(vector *vector);

void printVector(vector *vector);

void printVerboseVector(vector *vector);

void selectionSortVector(vector *vector, bool desc);

void bubbleSortVector(vector *vector, bool desc);

void insertionSortVector(vector *vector, bool desc);

#endif