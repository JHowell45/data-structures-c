#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include "single_linked_list.h"
}

class SingleLinkedListTest : public testing::Test {
  protected:
    linked_list_node_t* list;

    void
    SetUp() {
        list = new_single_linked_list_node(0);
    }

    void
    TearDown() {
        free_single_linked_list_node(list);
    }
};

TEST_F(SingleLinkedListTest, test_root) { EXPECT_EQ(list->data, 0); }

TEST_F(SingleLinkedListTest, test_push) {
    const int LENGTH = 3;
    for (int i = 1; i < LENGTH; i++) {
        single_linked_list_node_push(list, i);
    }
    int i = 0;
    linked_list_node_t* node = list;
    do {
        EXPECT_EQ(node->data, i);
        ++i;
        node = node->next;
    } while (i < LENGTH);
}

TEST_F(SingleLinkedListTest, test_insert) {
    for (int i = 1; i < 3; i++) {
        single_linked_list_node_push(list, i);
    }
    EXPECT_EQ(list->next->data, 1);
}