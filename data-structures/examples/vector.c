#include "vector.h"

int main(void) {
    vector *v = newVector();
    printVector(v);
    freeVector(v);
    return 0;
}