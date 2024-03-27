#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "single_linked_list.h"
#include "../../vector/include/vector.h"

void list_init(list *l, int data) {
    l->data = data;
    l->next = NULL;
}

list *new_list(int data) {
    list *l = malloc(sizeof(list));
    list_init(l, data);
    return l;
}

void list_push(list *l, list *next) {
    list *temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = next;
}

void list_pop(list *l) {

}

bool list_contains(list *l, int search) {
    list *temp = l;
    while (temp != NULL) {
        if (temp->data == search) {
            return true;
        }
        temp++;
    }
    return false;
}

list * list_search(list *l, int search) {
    list *temp = l;
    while (temp != NULL) {
        if (temp->data == search) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void list_insert(list *l, size_t index, int data) {

}

void list_remove(list *l, size_t index) {

}

vector * list_to_vector(list *l) {
    vector *v = new_vec(4);
    list *temp = l;
    while (temp != NULL) {
        vector_push(v, temp->data);
        temp = temp->next;
    }
    return v;
}

void list_destroy(list *l) {
    if (l->next != NULL) {
        list_destroy(l->next);
    }
    free(l);
}

void list_print(list *l) {
    list *temp = l;
    printf("(%d)", temp->data);
    while (temp->next != NULL) {
        temp = temp->next;
        printf("->(%d)", temp->data);
    }
    printf("\n");
    
}