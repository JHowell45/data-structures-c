#include <stdio.h>
#include "vector.h"

vector * createRandom() {
    vector *v = newVector();
    pushVector(v, 9);
    pushVector(v, 10);
    pushVector(v, 3);
    pushVector(v, 2);
    pushVector(v, 1);
    pushVector(v, 6);
    pushVector(v, 5);
    pushVector(v, 8);
    pushVector(v, 0);
    pushVector(v, 4);
    return v;
}

void basicTest() {
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
}

void testSelectionSort() {
    vector *v = createRandom();
    printVerboseVector(v);
    
    printf("Selection Sort Asc:\n");
    selectionSortVector(v, false);
    printVerboseVector(v);

    printf("Selection Sort Desc:\n");
    selectionSortVector(v, true);
    printVerboseVector(v);

    freeVector(v);
}

void testBubbleSort() {
    vector *v = createRandom();
    printVerboseVector(v);
    
    printf("Bubble Sort Asc:\n");
    bubbleSortVector(v, false);
    printVerboseVector(v);

    printf("Bubble Sort Desc:\n");
    bubbleSortVector(v, true);
    printVerboseVector(v);

    freeVector(v);
}

void testInsertionSort() {
    vector *v = createRandom();
    printVerboseVector(v);
    
    printf("Insertion Sort Asc:\n");
    insertionSortVector(v, false);
    printVerboseVector(v);

    printf("Insertion Sort Desc:\n");
    insertionSortVector(v, true);
    printVerboseVector(v);

    freeVector(v);
}

int main(void) {
    // basicTest();
    // testSelectionSort();
    // testBubbleSort();
    testInsertionSort();
    return 0;
}