#include <stdio.h>

#include "single_linked_list.h"
#include "../../vector/include/vector.h"

int main(void) {
    list *root = new_list(0);
    list_print(root);
    list_print(root);
    for (int i = 1; i < 20; i += 2) {
        list *new = new_list(i);
        list_push(root, new);
        list_print(root);
    }

    list *search = list_search(root, 5);
    list_print(search);

    // if (list_contains(root, 6)) {
    //     list *emptySearch = list_search(root, 6);
    //     list_print(emptySearch);
    // }

    vector *v = list_to_vector(root);
    vector_print(v);

    list_destroy(root);
    return 0;
}