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

void clearVector(vector *vector) {
    vector->size = 0;
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

void selectionSortVector(vector *vector, bool desc) {
    for (int firstIndex = 0; firstIndex < vector->size-1; firstIndex++) {
        int first = vector->items[firstIndex];
        int second = vector->items[firstIndex];
        int swapindex = firstIndex;
        for (int secondIndex = firstIndex+1; secondIndex < vector->size; secondIndex++) {
            int temp = vector->items[secondIndex];
            if (desc == true) {
                if (temp > second) {
                    second = temp;
                    swapindex = secondIndex;
                }
            } else {
                if (temp < second) {
                    second = temp;
                    swapindex = secondIndex;
                }
            }
        }
        if (firstIndex != swapindex) {
            vector->items[firstIndex] = second, vector->items[swapindex] = first;
            printVector(vector);
        }
    }
}

void swapIndexWithNext(vector *v, size_t itemIndex) {
    int temp = v->items[itemIndex+1];
    v->items[itemIndex+1] = v->items[itemIndex];
    v->items[itemIndex] = temp;
    printVector(v);
}

void bubbleSortVector(vector *vector, bool desc) {
    size_t swaps = 1;
    while (swaps != 0) {
        swaps = 0;
        for (int i = 0; i < vector->size-1; i++) {
            if (desc == false) {
                if (vector->items[i] > vector->items[i+1]) {
                    swapIndexWithNext(vector, i);
                    swaps++;
                }
            } else {
                if (vector->items[i] < vector->items[i+1]) {
                    swapIndexWithNext(vector, i);
                    swaps++;
                }
            }
        }
    }
}

void insertionSortVector(vector *vector, bool desc) {
    for (int i = 0; i < vector->size; i++) {
        int first = vector->items[i];
        int second = vector->items[i+1];
        if (desc == false) {
            if (first > second) {
                swapIndexWithNext(vector, i);
                if (i > 0) {
                    i -= 2;
                }
            }
        } else {
            if (first < second) {
                swapIndexWithNext(vector, i);
                if (i > 0) {
                    i -= 2;
                }
            }
        }
    }
}