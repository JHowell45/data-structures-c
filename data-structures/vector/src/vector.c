#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(vector *v, size_t capacity) {
    v->capacity = capacity;
    v->size = 0;
    v->arr = calloc(capacity, sizeof(int));
}

vector * new_vec(size_t capacity) {
    vector *v = malloc(sizeof(vector));
    vector_init(v, capacity);
    return v;
}

void vector_push(vector *v, int data) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->arr = realloc(v->arr, v->capacity * sizeof(int));
    }
    v->arr[v->size] = data;
    v->size++;
}

void vector_pop(vector *v) {
    v->size--;
}

int vector_get(vector* v, size_t index) {
    return v->arr[index];
}

void vector_insert(vector *v, size_t index, int data) {
    v->size++;
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->arr = realloc(v->arr, v->capacity * sizeof(int));
    }
    for (int i = v->size; i > index; i--) {
        v->arr[i] = v->arr[i-1];
    }
    v->arr[index] = data;
}

void vector_delete(vector *v, size_t index) {
    for (int i = index; i < v->size; i++) {
        v->arr[i] = v->arr[i+1];
    }
    v->size--;
}

void vector_destroy(vector *v) {
    free(v->arr);
    free(v);
}

void vector_print(vector *v) {
    printf("[");
    for (int i = 0; i < v->size; i++) {
        int number = v->arr[i];
        if (i == 0) {
            printf("%d", number);
        } else {
            printf(", %d", number);
        }
    }
    printf("]\n");
}