#ifndef B_TREE_H
#define B_TREE_H

typedef struct btree_s btree;

typedef struct btree_s {
    int data;
    btree *left;
    btree *right;
} btree;

void btree_init(btree *node, int data);

btree * new_btree(int data);

void btree_add_left(btree *node, btree *left);

void btree_add_right(btree *node, btree *right);

void btree_remove_left(btree *node);

void btree_remove_right(btree *node);

void btree_destroy(btree *node);

#endif