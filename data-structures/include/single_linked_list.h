#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stddef.h>

typedef struct linked_list {
    int data;
    struct linked_list* next;
} linked_list_t;

linked_list_t* new_single_linked_list(int data);

void free_single_linked_list(linked_list_t* ll);
void print_single_linked_list(linked_list_t* ll);

void single_linked_list_push(linked_list_t* ll, int data);
void single_linked_list_insert(linked_list_t* ll, int data, size_t index);
void single_linked_list_pop(linked_list_t* ll);
void single_linked_list_remove(linked_list_t* ll, size_t index);
linked_list_t* single_linked_list_get_node(linked_list_t* ll, int searchValue);

#endif