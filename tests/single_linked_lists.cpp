#include <gtest/gtest.h>

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

// Demonstrate some basic assertions.
TEST_F(SingleLinkedListTest, test_push) {
    single_linked_list_node_push(list, 1);
    EXPECT_EQ(list->data, 0);
}