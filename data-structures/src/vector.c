#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define VECTOR_CAPACITY 4

vector * newVector(void) {
    vector *v = malloc(sizeof(vector));
    v->capacity = VECTOR_CAPACITY;
    v->size = 0;
    v->items = calloc(VECTOR_CAPACITY, sizeof(int));
    return v;
}

void freeVector(vector *vector) {
    free(vector->items);
    free(vector);
}

void increaseInternalArraySizeCheck(vector *vector) {
    if (vector->size > vector->capacity) {
        vector->capacity *= 2;
        vector->items = realloc(vector->items, sizeof(int) * vector->capacity);
    }
}

void pushVector(vector *vector, int value) {
    vector->size++;
    increaseInternalArraySizeCheck(vector);
    vector->items[vector->size - 1] = value;
}

void insertVector(vector *vector, int value, size_t index) {
    vector->size++;
    increaseInternalArraySizeCheck(vector);
    for (int i = vector->size-1; i >= index; i--) {
        vector->items[i+1] = vector->items[i];
    }
    vector->items[index] = value;
}

void popVector(vector *vector) {
    vector->size--;
}

void removeVector(vector *vector, size_t index) {
    for (int i = index+1; i < vector->size; i++) {
        vector->items[i-1] = vector->items[i];
    }
    vector->size--;
}

int indexOfVector(vector *vector, int search) {
    for (int i = 0; i < vector->size; i++) {
        if (vector->items[i] == search) {
            return i;
        }
    }
    return -1;
}

bool isEmptyVector(vector *vector) {
    return vector->size == 0;
}

void printVector(vector *vector) {
    printf("[");
    for (int i = 0; i < vector->size; i++) {
        int item = vector->items[i];
        if (i == 0) {
            printf("%d", item);
        } else {
            printf(", %d", item);
        }
    }
    printf("]\n");
}

void printVerboseVector(vector *vector) {
    printf("Vector {\n");
    printf("\tCount: %zu\n", vector->size);
    printf("\tCapacity: %zu\n", vector->capacity);
    printf("\tItems: ");
    printVector(vector);
    printf("}\n");
}