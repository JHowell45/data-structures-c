#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(vector *v, size_t capacity) {
    v->capacity = capacity;
    v->size = 0;
    v->arr = malloc(sizeof(int) * capacity);
}

vector * new_vec(size_t capacity) {
    vector *v = malloc(sizeof(vector));
    vector_init(v, capacity);
    return v;
}

void vector_push(vector *v, int data) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->arr = realloc(v->arr, v->capacity);
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
    if (v->size >= v->capacity) {
        v->capacity *= 2;
    }
    int *temp = malloc(sizeof(int) * v->capacity);
}

void vector_delete(vector *v, size_t index) {

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