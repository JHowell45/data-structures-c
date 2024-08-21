#include <stdio.h>

#include "single_linked_list.h"

int
main(void) {
  linked_list_t* root = new_single_linked_list(0);
  print_single_linked_list(root);

  for (int i = 1; i <= 10; i++) {
    push_single_linked_list(root, i);
    print_single_linked_list(root);
  }

  insert_single_linked_list(root, 1000, 4);
  print_single_linked_list(root);

  remove_single_linked_list(root, 5);
  print_single_linked_list(root);

  size_t superLargeValue = 1000;
  for (int i = 0; i <= superLargeValue; i++) {
    insert_single_linked_list(root, 2 * i, 6);
  }

  linked_list_t* search = getNode_single_linked_list(root, 10);
  if (search == NULL) {
    printf("NOT FOUND\n");
  } else {
    print_single_linked_list(search);
  }

  free_single_linked_list(root);
  return 0;
}