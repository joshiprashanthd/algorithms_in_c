#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int insert(struct Node** base_node, char* value) {
  if (value == NULL) return 0;

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->value = value;

  if ((*base_node) == NULL) {
    *base_node = newNode;
  } else {
    struct Node* temp = *base_node;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    temp = NULL;
  }

  return 1;
}

int search(struct Node* base_node, char* value) {
  struct Node* temp = base_node;

  while (temp != NULL) {
    if (temp->value == value) return 1;
    temp = temp->next;
  }

  return 0;
}

int delete (struct Node** base_node, char* value) {
  assert(*base_node != NULL);

  int result = search(*base_node, value);

  if (result != 1) return 0;

  struct Node* temp = *base_node;

  // temp points to previous node of the node to remove
  while ((temp->next)->value != value) temp = temp->next;

  struct Node* node = temp->next;
  temp->next = node->next;

  free(node);

  return 1;
}

void show(struct Node* base_node) {
  struct Node* temp = base_node;

  while (temp->next != NULL) {
    printf("[%s] -> ", temp->value);
    temp = temp->next;
  }

  printf("[%s]\n", temp->value);
}

void test_linked_list() {
  printf("Linked List Test started\n");

  
  struct LinkedList ll = {0, NULL};

  printf("\tTest `insert`\n");
  assert(insert(&ll.base_node, "A") == 1);
  assert(insert(&ll.base_node, "B") == 1);
  assert(insert(&ll.base_node, NULL) == 0);
  printf("\tTest `insert` completed\n");

  printf("\tTest `search`\n");
  assert(search(ll.base_node, "A") == 1);
  assert(search(ll.base_node, "B") == 1);
  assert(search(ll.base_node, "9") == 0);
  printf("\tTest `search` completed\n");

  printf("\tTest `remove`\n");
  assert(delete (&ll.base_node, "B") == 1);
  assert(search(ll.base_node, "B") == 0);
  printf("\tTest `remove` completed\n");

  printf("Linked List Test Completed");
}