#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int append(struct Node** root, char* value) {
  if (value == NULL) return 0;

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->next = NULL;

  if ((*root) == NULL) {
    *root = new_node;
  } else {
    struct Node* temp = *root;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    temp = NULL;
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
  assert(*root != NULL);

  int result = search(*root, value);

  if (result != 1) return 0;

  struct Node* temp = *root;

  // temp points to previous node of the node to remove
  while ((temp->next)->value != value) temp = temp->next;

  struct Node* node = temp->next;
  temp->next = node->next;

  free(node);

  return 1;
}

void show(struct Node* root) {
  struct Node* temp = root;

  while (temp->next != NULL) {
    printf("[%s] -> ", temp->value);
    temp = temp->next;
  }

  printf("[%s]\n", temp->value);
}

char* pop(struct Node** root) {
  if (*root == NULL) return NULL;

  struct Node* temp = *root;
  while (temp->next != NULL) temp = temp->next;

  char* target_value = temp->value;
  free(temp);

  return target_value;
}

void test_linked_list() {
  printf("Linked List Test started\n");

  struct LinkedList ll = {0, NULL};

  assert(append(&ll.root, "A") == 1);
  assert(append(&ll.root, "B") == 1);
  assert(append(&ll.root, NULL) == 0);
  printf("\tTest `append` completed\n");

  assert(search(ll.root, "A") == 1);
  assert(search(ll.root, "B") == 1);
  assert(search(ll.root, "9") == 0);
  printf("\tTest `search` completed\n");

  assert(delete (&ll.root, "B") == 1);
  assert(search(ll.root, "B") == 0);
  printf("\tTest `delete` completed\n");

  assert(pop(&ll.root) == "A");
  assert(pop(&ll.root) == NULL);
  printf("\tTest `pop` completed\n");

  printf("Linked List Test Completed");
}