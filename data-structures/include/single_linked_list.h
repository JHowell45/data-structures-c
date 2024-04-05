#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stddef.h>

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} LinkedList;

LinkedList * newSingleLinkedList(int data);

void freeSingleLinkedList(LinkedList *ll);

void pushSingleLinkedList(LinkedList *ll, int data);

void insertSingleLinkedList(LinkedList *ll, int data, size_t index);

void popSingleLinkedList(LinkedList *ll);

void removeSingleLinkedList(LinkedList *ll, size_t index);

void printSingleLinkedList(LinkedList *ll);

#endif