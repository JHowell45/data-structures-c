#include <stdlib.h>
#include <stdio.h>
#include "single_linked_list.h"

LinkedList * newSingleLinkedList(int data) {
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->data = data;
    ll->next = NULL;
    return ll;
}

void freeSingleLinkedList(LinkedList *ll) {
    if (ll->next != NULL) {
        freeSingleLinkedList(ll->next);
    }
    free(ll);
}

void pushSingleLinkedList(LinkedList *ll, int data) {
    if (ll->next != NULL) {
        pushSingleLinkedList(ll->next, data);
    } else {
        ll->next = newSingleLinkedList(data);
    }
}

void insertSingleLinkedList(LinkedList *ll, int data, size_t index) {
    size_t current = 0;
    LinkedList *temp = ll;
    while (current < index-1) {
        temp = temp->next;
        current++;
    }
    LinkedList *newNode = newSingleLinkedList(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void popSingleLinkedList(LinkedList *ll) {

}

void removeSingleLinkedList(LinkedList *ll, size_t index) {
    size_t current = 0;
    LinkedList *temp = ll;
    while (current < index-1) {
        temp = temp->next;
        current++;
    }
    LinkedList *toFree = temp->next;
    temp->next = temp->next->next;
    free(toFree);
}

void printSingleLinkedList(LinkedList *ll) {
    printf("(%d)", ll->data);
    if (ll->next != NULL) {
        printf("->");
        printSingleLinkedList(ll->next);
    } else {
        printf("\n");
    }
}

LinkedList * getNodeSingleLinkedList(LinkedList *ll, int searchValue) {
    LinkedList *temp = ll;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}