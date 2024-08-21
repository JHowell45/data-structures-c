#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define VECTOR_CAPACITY 4

vector_t*
new_vector(void) {
    vector_t* v = malloc(sizeof(vector_t));
    v->capacity = VECTOR_CAPACITY;
    v->size = 0;
    v->items = calloc(VECTOR_CAPACITY, sizeof(int));
    return v;
}

void
free_vector(vector_t* vector) {
    free(vector->items);
    free(vector);
}

void
print_vector(vector_t* vector) {
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

void
print_verbose_vector(vector_t* vector) {
    printf("_vector {\n");
    printf("\tCount: %zu\n", vector->size);
    printf("\tCapacity: %zu\n", vector->capacity);
    printf("\tItems: ");
    print_vector(vector);
    printf("}\n");
}

static void
increase_internal_array_size_check(vector_t* vector) {
    if (vector->size > vector->capacity) {
        vector->capacity *= 2;
        vector->items = realloc(vector->items, sizeof(int) * vector->capacity);
    }
}

void
vector_push(vector_t* vector, int value) {
    vector->size++;
    increase_internal_array_size_check(vector);
    vector->items[vector->size - 1] = value;
}

void
vector_insert(vector_t* vector, int value, size_t index) {
    vector->size++;
    increase_internal_array_size_check(vector);
    for (int i = vector->size - 1; i >= index; i--) {
        vector->items[i + 1] = vector->items[i];
    }
    vector->items[index] = value;
}

void
vector_pop(vector_t* vector) {
    vector->size--;
}

void
vector_remove(vector_t* vector, size_t index) {
    for (int i = index + 1; i < vector->size; i++) {
        vector->items[i - 1] = vector->items[i];
    }
    vector->size--;
}

void
vector_clear(vector_t* vector) {
    vector->size = 0;
}

int
vector_index_of(vector_t* vector, int search) {
    for (int i = 0; i < vector->size; i++) {
        if (vector->items[i] == search) {
            return i;
        }
    }
    return -1;
}

bool
vector_is_empty(vector_t* vector) {
    return vector->size == 0;
}

void
vector_selection_sort(vector_t* vector, bool desc) {
    for (int firstIndex = 0; firstIndex < vector->size - 1; firstIndex++) {
        int first = vector->items[firstIndex];
        int second = vector->items[firstIndex];
        int swapindex = firstIndex;
        for (int secondIndex = firstIndex + 1; secondIndex < vector->size; secondIndex++) {
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
            print_vector(vector);
        }
    }
}

static void
swap_index_with_next(vector_t* v, size_t itemIndex) {
    int temp = v->items[itemIndex + 1];
    v->items[itemIndex + 1] = v->items[itemIndex];
    v->items[itemIndex] = temp;
    print_vector(v);
}

void
vector_bubble_sort(vector_t* vector, bool desc) {
    size_t swaps = 1;
    while (swaps != 0) {
        swaps = 0;
        for (int i = 0; i < vector->size - 1; i++) {
            if (desc == false) {
                if (vector->items[i] > vector->items[i + 1]) {
                    swap_index_with_next(vector, i);
                    swaps++;
                }
            } else {
                if (vector->items[i] < vector->items[i + 1]) {
                    swap_index_with_next(vector, i);
                    swaps++;
                }
            }
        }
    }
}

void
vector_insertion_sort(vector_t* vector, bool desc) {
    for (int i = 0; i < vector->size; i++) {
        int first = vector->items[i];
        int second = vector->items[i + 1];
        if (desc == false) {
            if (first > second) {
                swap_index_with_next(vector, i);
                if (i > 0) {
                    i -= 2;
                }
            }
        } else {
            if (first < second) {
                swap_index_with_next(vector, i);
                if (i > 0) {
                    i -= 2;
                }
            }
        }
    }
}