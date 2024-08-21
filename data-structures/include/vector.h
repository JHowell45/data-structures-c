#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t capacity;
    size_t size;
    int* items;
} vector_t;

vector_t* new_vector(void);

void free_vector(vector_t* vector);
void print_vector(vector_t* vector);
void print_verbose_vector(vector_t* vector);

void vector_push(vector_t* vector, int value);
void vector_insert(vector_t* vector, int value, size_t index);
void vector_pop(vector_t* vector);
void vector_remove(vector_t* vector, size_t index);
void vector_clear(vector_t* vector);
int vector_index_of(vector_t* vector, int search);
bool vector_is_empty(vector_t* vector);
void vector_selection_sort(vector_t* vector, bool desc);
void vector_bubble_sort(vector_t* vector, bool desc);
void vector_insertion_sort(vector_t* vector, bool desc);

#endif