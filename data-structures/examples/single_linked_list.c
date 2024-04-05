#include "single_linked_list.h"

int main(void) {
    LinkedList *ll = newSingleLL(0);
    printSingleLL(ll);

    for (int i = 1; i <= 5; i++) {
        pushSingleLL(ll, i);
        printSingleLL(ll);
    }
    return 0;
}