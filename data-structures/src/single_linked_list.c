#include <stdlib.h>
#include <stdio.h>
#include "single_linked_list.h"

LinkedList * newSingleLL(int data) {
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->data = data;
    ll->next = NULL;
    return ll;
}

void freeSingleLL(LinkedList *ll) {
    free(ll);
}

void pushSingleLL(LinkedList *ll, int data) {
    if (ll->next != NULL) {
        pushSingleLL(ll->next, data);
    } else {
        ll->next = newSingleLL(data);
    }
}

void printSingleLL(LinkedList *ll) {
    printf("(%d)", ll->data);
    if (ll->next != NULL) {
        printf("->");
        printSingleLL(ll->next);
    } else {
        printf("\n");
    }
}