#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"

linked_list_node_t*
new_single_linked_list_node(int data) {
    linked_list_node_t* ll = malloc(sizeof(linked_list_node_t));
    ll->data = data;
    ll->next = NULL;
    return ll;
}

void
free_single_linked_list_node(linked_list_node_t* ll) {
    if (ll->next != NULL) {
        free_single_linked_list_node(ll->next);
    }
    free(ll);
}

void
print_single_linked_list_node(linked_list_node_t* ll) {
    printf("(%d)", ll->data);
    if (ll->next != NULL) {
        printf("->");
        print_single_linked_list_node(ll->next);
    } else {
        printf("\n");
    }
}

void
single_linked_list_node_push(linked_list_node_t* ll, int data) {
    if (ll->next != NULL) {
        single_linked_list_node_push(ll->next, data);
    } else {
        ll->next = new_single_linked_list_node(data);
    }
}

void
single_linked_list_node_insert(linked_list_node_t* ll, int data, size_t index) {
    size_t current = 0;
    linked_list_node_t* temp = ll;

    while (current < index - 1) {
        temp = temp->next;
        current++;
    }
    linked_list_node_t* newNode = new_single_linked_list_node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void
single_linked_list_node_pop(linked_list_node_t* ll) {}

void
single_linked_list_node_remove(linked_list_node_t* ll, size_t index) {
    size_t current = 0;
    linked_list_node_t* temp = ll;
    while (current < index - 1) {
        temp = temp->next;
        current++;
    }
    linked_list_node_t* toFree = temp->next;
    temp->next = temp->next->next;
    free(toFree);
}

linked_list_node_t*
single_linked_list_node_get_node(linked_list_node_t* ll, int searchValue) {
    linked_list_node_t* temp = ll;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Linked List:
single_linked_list_t*
new_single_linked_list(void) {
    single_linked_list_t* list = malloc(sizeof(single_linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void
free_single_linked_list(single_linked_list_t* list) {
    free_single_linked_list_node(list->head);
    free(list);
}