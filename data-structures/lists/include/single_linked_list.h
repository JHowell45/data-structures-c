#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>
#include "../../vector/include/vector.h"

typedef struct single_linked_list list;

typedef struct single_linked_list {
    int data;
    list *next;
} list;

void list_init(list *l, int data);

list *new_list(int data);

void list_push(list *l, list *next);

void list_pop(list *l);

bool list_contains(list *l, int search);

list * list_search(list *l, int search);

void list_insert(list *l, size_t index, int data);

void list_remove(list *l, size_t index);

vector * list_to_vector(list *l);

void list_destroy(list *l);

void list_print(list *l);

#endif