#include "doubly_linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int append(struct Node** root, char* value) {
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

int search(struct Node* root, char* value) {
  struct Node* temp = root;

  while (temp != NULL) {
    if (temp->value == value) return 1;
    temp = temp->next;
  }

  return 0;
}

int delete (struct Node** root, char* value) {
  if (value == NULL) return 0;
  if ((*root) == NULL) return 0;

  struct Node* temp = *root;

  if (temp->value == value) {
    if (temp->next != NULL) {
      (temp->next)->prev = NULL;
      *root = temp->next;
    }

    free(temp);
    return 1;
  }

  while (temp->next != NULL && (temp->next)->value != value) temp = temp->next;

  // cannot find node with value `value`
  if (temp->next == NULL) return 0;

  struct Node* target = temp->next;
  temp->next = target->next;
  (temp->next)->prev = temp;
  free(target);

  return 1;
}

void test_doubly_linked_list() {
  printf("\nDoubly Linked List Test Started:\n");

  struct DoublyLL dll = {0, NULL};

  printf("\tTest `insert`\n");
  assert(append(&dll.root, "A") == 1);
  assert(append(&dll.root, "B") == 1);
  assert(append(&dll.root, "D") == 1);
  printf("\tTest `insert` completed\n");

  printf("\tTest `search`\n");
  assert(search(dll.root, "A") == 1);
  assert(search(dll.root, "C") == 0);
  printf("\tTest `search` completed\n");

  printf("\tTest `delete`\n");
  assert(delete (&dll.root, "B") == 1);
  assert(search(dll.root, "B") == 0);

  assert(delete (&dll.root, "A") == 1);
  assert(search(dll.root, "A") == 0);

  assert(delete (&dll.root, "B") == 0);
  printf("\tTest `insert` completed\n");

  printf("Doublu Linked List Test Completed\n");
}