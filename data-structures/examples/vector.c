#include "vector.h"

int main(void) {
    vector *v = newVector();
    printVerboseVector(v);
    for (int i = 0; i < 20; i++) {
        pushVector(v, i);
    }
    printVerboseVector(v);
    for (int i = 100; i > 80; i--) {
        insertVector(v, 100, 5);
        printVerboseVector(v);
    }
    for (int i = 0; i < 30; i++) {
        popVector(v);
        printVerboseVector(v);
    }
    for (int i = 0; i < 5; i++) {
        removeVector(v, 0);
        printVerboseVector(v);
    }
    printVerboseVector(v);
    freeVector(v);
    return 0;
}