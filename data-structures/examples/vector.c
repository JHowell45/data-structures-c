#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vector.h"

int main(void) {
    size_t max = 30;
    vector *vec = new_vec(4);
    vector_print(vec);
    for (int i = 0; i < max; i++) {
        vector_push(vec, i);
        vector_print(vec);
    }
    for (int i = 0; i < max/2; i++) {
        vector_pop(vec);
        vector_print(vec);
    }

    vector_insert(vec, 3, 100);
    vector_print(vec);

    vector_insert(vec, 0, 100);
    vector_print(vec);

    vector_insert(vec, vec->size-1, 100);
    vector_print(vec);

    vector_insert(vec, vec->size, 100);
    vector_print(vec);

    vector_delete(vec, 0);
    vector_print(vec);

    for (int i = 0; i < 3; i++) {
        vector_delete(vec, vec->size);
        vector_print(vec);
    }

    vector_delete(vec, 5);
    vector_print(vec);

    vector_destroy(vec);
    return 0;
}