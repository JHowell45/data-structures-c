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