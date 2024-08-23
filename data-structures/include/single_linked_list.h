#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stddef.h>

typedef struct linked_list_node {
    int data;
    struct linked_list_node* next;
} linked_list_node_t;

linked_list_node_t* new_single_linked_list_node(int data);

void free_single_linked_list_node(linked_list_node_t* ll);
void print_single_linked_list_node(linked_list_node_t* ll);

void single_linked_list_node_push(linked_list_node_t* ll, int data);
void single_linked_list_node_insert(linked_list_node_t* ll, int data, size_t index);
void single_linked_list_node_pop(linked_list_node_t* ll);
void single_linked_list_node_remove(linked_list_node_t* ll, size_t index);
linked_list_node_t* single_linked_list_node_get_node(linked_list_node_t* ll, int searchValue);

typedef struct single_linked_list {
    linked_list_node_t* head;
    linked_list_node_t* tail;
    size_t length;
} single_linked_list_t;

single_linked_list_t* new_single_linked_list(void);

void free_single_linked_list(single_linked_list_t* list);

#endif