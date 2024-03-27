#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../../vector/include/vector.h"

typedef struct binary_tree_s binary_tree;

typedef struct binary_tree_s {
    int data;
    binary_tree* left;
    binary_tree* right;
} binary_tree;

void binary_tree_init(binary_tree *node, int data);

binary_tree * new_binary_tree(int data);

void binary_tree_add_left(binary_tree* node, binary_tree* left);

void binary_tree_add_right(binary_tree* node, binary_tree* right);

void binary_tree_destroy(binary_tree* node);

vector * binary_tree_depth_first_search(binary_tree* node, const char* type);

vector * binary_tree_breadth_first_search(binary_tree* node, const char* type);

#endif