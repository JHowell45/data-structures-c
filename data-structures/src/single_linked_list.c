#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"

linked_list_t*
new_single_linked_list(int data) {
    linked_list_t* ll = malloc(sizeof(linked_list_t));
    ll->data = data;
    ll->next = NULL;
    return ll;
}

void
free_single_linked_list(linked_list_t* ll) {
    if (ll->next != NULL) {
        free_single_linked_list(ll->next);
    }
    free(ll);
}

void
push_single_linked_list(linked_list_t* ll, int data) {
    if (ll->next != NULL) {
        push_single_linked_list(ll->next, data);
    } else {
        ll->next = new_single_linked_list(data);
    }
}

void
insert_single_linked_list(linked_list_t* ll, int data, size_t index) {
    size_t current = 0;
    linked_list_t* temp = ll;

    while (current < index - 1) {
        temp = temp->next;
        current++;
    }
    linked_list_t* newNode = new_single_linked_list(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void
pop_single_linked_list(linked_list_t* ll) {}

void
remove_single_linked_list(linked_list_t* ll, size_t index) {
    size_t current = 0;
    linked_list_t* temp = ll;
    while (current < index - 1) {
        temp = temp->next;
        current++;
    }
    linked_list_t* toFree = temp->next;
    temp->next = temp->next->next;
    free(toFree);
}

void
print_single_linked_list(linked_list_t* ll) {
    printf("(%d)", ll->data);
    if (ll->next != NULL) {
        printf("->");
        print_single_linked_list(ll->next);
    } else {
        printf("\n");
    }
}

linked_list_t*
getNode_single_linked_list(linked_list_t* ll, int searchValue) {
    linked_list_t* temp = ll;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}