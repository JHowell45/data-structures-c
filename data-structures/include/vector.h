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

void push_vector(vector_t* vector, int value);

void insert_vector(vector_t* vector, int value, size_t index);

void pop_vector(vector_t* vector);

void remove_vector(vector_t* vector, size_t index);

void clear_vector(vector_t* vector);

int index_of_vector(vector_t* vector, int search);

bool is_empty_vector(vector_t* vector);

void print_vector(vector_t* vector);

void print_verbose_vector(vector_t* vector);

void selection_sort_vector(vector_t* vector, bool desc);

void bubble_sort_vector(vector_t* vector, bool desc);

void insertion_sort_vector(vector_t* vector, bool desc);

#endif