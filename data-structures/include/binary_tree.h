#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include "vector.h"

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

BinaryTreeNode * newBinaryTree(int data);

void freeBinaryTree(BinaryTreeNode *node);

void insertLeftBinaryTree(BinaryTreeNode *node, BinaryTreeNode *newNode);

void insertRightBinaryTree(BinaryTreeNode *node, BinaryTreeNode *newNode);

void addBinaryTree(BinaryTreeNode *node, int data);

vector * dfsToVecBinaryTree(BinaryTreeNode *node, char *type);

void printDepthFirstSearchBinaryTree(BinaryTreeNode *node, char *type);

void printBinaryTree(BinaryTreeNode *node);

#endif