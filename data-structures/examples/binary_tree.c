#include <stdio.h>
#include "binary_tree.h"
#include "vector.h"

void testDepthFirstSearchTraversals(void) {
    BinaryTreeNode *root = newBinaryTree(1);
    BinaryTreeNode *left = newBinaryTree(2);
    insertLeftBinaryTree(left, newBinaryTree(4));
    insertRightBinaryTree(left, newBinaryTree(5));

    BinaryTreeNode *right = newBinaryTree(3);
    insertLeftBinaryTree(right, newBinaryTree(6));
    insertRightBinaryTree(right, newBinaryTree(7));

    insertLeftBinaryTree(root, left);
    insertRightBinaryTree(root, right);
    

    printf("INORDER: ");
    printDepthFirstSearchBinaryTree(root, "inorder");

    printf("PREORDER: ");
    printDepthFirstSearchBinaryTree(root, "preorder");

    printf("POSTORDER: ");
    printDepthFirstSearchBinaryTree(root, "postorder");
    printf("\n");

    freeBinaryTree(root);
}

int main(void) {
    testDepthFirstSearchTraversals();
    return 0;
}

