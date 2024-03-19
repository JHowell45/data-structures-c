#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stddef.h>

typedef struct single_linked_list list;

typedef struct single_linked_list {
    int data;
    list *next;
} list;

void list_init(list *l, int data);

list *new_list(int data);

void list_push(list *l, int data);

void list_pop(list *l);

void list_insert(list *l, size_t index, int data);

void list_remove(list *l, size_t index);

void list_destroy(list *l);

#endif