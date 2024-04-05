#include <stdio.h>
#include "single_linked_list.h"

int main(void) {
    LinkedList *root = newSingleLinkedList(0);
    printSingleLinkedList(root);

    for (int i = 1; i <= 10; i++) {
        pushSingleLinkedList(root, i);
        printSingleLinkedList(root);
    }

    insertSingleLinkedList(root, 1000, 4);
    printSingleLinkedList(root);

    removeSingleLinkedList(root, 5);
    printSingleLinkedList(root);

    size_t superLargeValue = 1000;
    for (int i = 0; i <= superLargeValue; i++) {
        insertSingleLinkedList(root, 2*i, 6);
    }

    LinkedList *search = getNodeSingleLinkedList(root, 10);
    if (search == NULL) {
        printf("NOT FOUND\n");
    } else {
        printSingleLinkedList(search);
    }

    freeSingleLinkedList(root);
    return 0;
}