#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stddef.h>

typedef struct {
  int data;
  struct linked_list_t* next;
} linked_list_t;

linked_list_t* new_single_linked_list(int data);

void free_single_linked_list(linked_list_t* ll);
void push_single_linked_list(linked_list_t* ll, int data);
void insert_single_linked_list(linked_list_t* ll, int data, size_t index);
void pop_single_linked_list(linked_list_t* ll);
void remove_single_linked_list(linked_list_t* ll, size_t index);
linked_list_t* getNode_single_linked_list(linked_list_t* ll, int searchValue);
void print_single_linked_list(linked_list_t* ll);

#endif