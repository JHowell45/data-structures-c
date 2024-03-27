#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include "../../vector/include/vector.h"

void binary_tree_init(binary_tree *node, int data) {
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

binary_tree * new_binary_tree(int data) {
    binary_tree *node = malloc(sizeof(binary_tree));
    binary_tree_init(node, data);
    return node;
}

void binary_tree_add_left(binary_tree* node, binary_tree* left) {
    node->left = left;
}

void binary_tree_add_right(binary_tree* node, binary_tree* right) {
    node->right = right;
}

void binary_tree_destroy(binary_tree* node) {
    free(node->left);
    free(node->right);
    free(node);
}

vector * inorder_depth_first_search(vector* v, binary_tree* node) {
    if (node->left != NULL) {
        inorder_depth_first_search(v, node->left);
    }
    vector_push(v, node->data);
    if (node->right != NULL) {
        inorder_depth_first_search(v, node->right);
    }
    return v;
}

vector * preorder_depth_first_search(vector* v, binary_tree* node) {
    return v;
}

vector * postorder_depth_first_search(vector* v, binary_tree* node) {
    return v;
}

vector * binary_tree_depth_first_search(binary_tree* node, const char* type) {
    vector* v = new_vec(4);
    if (strcmp(type, "inorder") == 0) {
        inorder_depth_first_search(v, node);
    } else if (strcmp(type, "preorder") == 0) {
        preorder_depth_first_search(v, node);
    } else if (strcmp(type, "postorder") == 0) {
        postorder_depth_first_search(v, node);
    }
    return v;
}

vector * binary_tree_breadth_first_search(binary_tree* node, const char* type) {
    vector* v = new_vec(4);
    return v;
}