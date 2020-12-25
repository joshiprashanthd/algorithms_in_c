#include "doubly_linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int insert(struct Node** root, char* value) {
  if (value == NULL) return 0;

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->value = value;

  if ((*root) == NULL)
    *root = new_node;
  else {
    struct Node* temp = *root;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
  }

  return 1;
}

void test_doubly_linked_list() {
  printf("\nDoubly Linked List Test Started:\n");

  struct DoublyLL dll = {0, NULL};

  printf("\tTest `insert`\n");
  assert(insert(&dll.root, "A") == 1);
  assert(insert(&dll.root, "B") == 1);
  printf("\tTest `insert` completed\n");

  printf("\tTest `insert`\n");
  assert(insert(&dll.root, "A") == 1);
  assert(insert(&dll.root, "B") == 1);
  printf("\tTest `insert` completed\n");

  printf("\tTest `insert`\n");
  assert(insert(&dll.root, "A") == 1);
  assert(insert(&dll.root, "B") == 1);
  printf("\tTest `insert` completed\n");
}