#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "./linked_list/linked_list.h"

void test_linked_list() {
  printf("Test started\n");

  struct LinkedList ll = {0, NULL};
  insert(&ll.base_node, "A");
  insert(&ll.base_node, "B");
  insert(&ll.base_node, "9");

  printf("Test `search` function\n");
  assert(search(ll.base_node, "A") == 1);
  assert(search(ll.base_node, "B") == 1);
  assert(search(ll.base_node, "9") == 1);
  printf("Test `search` function completed\n");

  printf("Test `remove` function\n");
  assert(delete (&ll.base_node, "B") == 1);
  assert(search(ll.base_node, "B") == 0);
  printf("Test `remove` function completed\n");

  printf("All Test Completed");
}

int main(int argc, char** argv) {
  test_linked_list();

  return 0;
}