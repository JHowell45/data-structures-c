#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H


typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} LinkedList;

LinkedList * newSingleLL(int data);

void freeSingleLL(LinkedList *ll);

void pushSingleLL(LinkedList *ll, int data);

void printSingleLL(LinkedList *ll);

#endif