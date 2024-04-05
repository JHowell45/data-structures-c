#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "binary_tree.h"
#include "vector.h"

BinaryTreeNode * newBinaryTree(int data) {
    BinaryTreeNode *n = malloc(sizeof(BinaryTreeNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void freeBinaryTree(BinaryTreeNode *node) {
    if (node->left != NULL) {
        freeBinaryTree(node->left);
    }
    if (node->right != NULL) {
        freeBinaryTree(node->right);
    }
    free(node);
}

void insertLeftBinaryTree(BinaryTreeNode *node, BinaryTreeNode *newNode) {
    node->left = newNode;
}

void insertRightBinaryTree(BinaryTreeNode *node, BinaryTreeNode *newNode) {
    node->right = newNode;
}

void addBinaryTree(BinaryTreeNode *node, int data) {
    if (data < node->data) {
        if (node->left == NULL) {
            node->left = newBinaryTree(data);
        } else {
            addBinaryTree(node->left, data);
        }
    } else {
        if (node->right == NULL) {
            node->right = newBinaryTree(data);
        } else {
            addBinaryTree(node->right, data);
        }
    }   
}

void inorderDFSBinaryTree(BinaryTreeNode *node, vector *vec) {
    if (node->left != NULL) {
        inorderDFSBinaryTree(node->left, vec);
    }
    pushVector(vec, node->data);
    if (node->right != NULL) {
        inorderDFSBinaryTree(node->right, vec);
    }
}

void preorderDFSBinaryTree(BinaryTreeNode *node, vector *vec) {
    pushVector(vec, node->data);
    if (node->left != NULL) {
        preorderDFSBinaryTree(node->left, vec);
    }
    if (node->right != NULL) {
        preorderDFSBinaryTree(node->right, vec);
    }
}

void postorderDFSBinaryTree(BinaryTreeNode *node, vector *vec) {
    if (node->left != NULL) {
        postorderDFSBinaryTree(node->left, vec);
    }
    if (node->right != NULL) {
        postorderDFSBinaryTree(node->right, vec);
    }
    pushVector(vec, node->data);
}

vector * dfsToVecBinaryTree(BinaryTreeNode *node, char *type) {
    vector *order = newVector();
    if (strcmp(type, "inorder") == 0) {
        inorderDFSBinaryTree(node, order);
    } else if (strcmp(type, "preorder") == 0) {
        preorderDFSBinaryTree(node, order);
    } else if (strcmp(type, "postorder") == 0) {
        postorderDFSBinaryTree(node, order);
    }
    return order;
}

void printDepthFirstSearchBinaryTree(BinaryTreeNode *node, char *type) {
    vector *vec = dfsToVecBinaryTree(node, type);
    printVector(vec);
    freeVector(vec);
}

void printBinaryTree(BinaryTreeNode *node) {

}