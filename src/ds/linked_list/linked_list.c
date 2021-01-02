#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct LinkedList* linked_list_new() {
  struct LinkedList* ll = (struct LinkedList*)malloc(sizeof(struct LinkedList));
  ll->count = 0;
  ll->root = NULL;
  return ll;
}

int linked_list_append(struct LinkedList** linked_list, char* value) {
  assert(value != NULL);

  struct LinkedListNode* new_node =
      (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
  new_node->value = value;
  new_node->next = NULL;

  if ((*linked_list)->root == NULL) {
    (*linked_list)->root = new_node;
  } else {
    struct LinkedListNode* temp = (*linked_list)->root;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    temp = NULL;
  }

  (*linked_list)->count++;

  return 1;
}

int linked_list_search(struct LinkedList* linked_list, char* value) {
  assert(value != NULL);

  struct LinkedListNode* temp = linked_list->root;

  while (temp != NULL) {
    if (temp->value == value) return 1;
    temp = temp->next;
  }

  return 0;
}

int linked_list_delete(struct LinkedList** linked_list, char* value) {
  assert((*linked_list)->root != NULL);

  int result = linked_list_search(*linked_list, value);

  if (result != 1) return 0;

  struct LinkedListNode* temp = (*linked_list)->root;

  // temp points to previous node of the node to remove
  while ((temp->next)->value != value) temp = temp->next;

  struct LinkedListNode* node = temp->next;
  temp->next = node->next;
  free(node);

  (*linked_list)->count--;

  return 1;
}

void linked_list_show(struct LinkedList* linked_list) {
  struct LinkedListNode* temp = linked_list->root;

  while (temp->next != NULL) {
    printf("[%s] -> ", temp->value);
    temp = temp->next;
  }

  printf("[%s]\n", temp->value);
}

char* linked_list_pop(struct LinkedList** linked_list) {
  struct LinkedListNode* root = (*linked_list)->root;
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    char* target_value = root->value;
    (*linked_list)->root = NULL;
    (*linked_list)->count = 0;
    return target_value;
  }

  struct LinkedListNode* temp = root;
  while ((temp->next)->next != NULL) temp = temp->next;

  struct LinkedListNode* target_node = temp->next;
  char* target_value = target_node->value;
  temp->next = NULL;
  free(target_node);

  (*linked_list)->count--;

  return target_value;
}

void test_linked_list() {
  printf("Linked List Test started\n");

  struct LinkedList* ll = linked_list_new();

  assert(linked_list_append(&ll, "A") == 1);
  assert(linked_list_append(&ll, "B") == 1);
  printf("\tTest `append` completed\n");

  assert(linked_list_search(ll, "A") == 1);
  assert(linked_list_search(ll, "B") == 1);
  assert(linked_list_search(ll, "9") == 0);
  printf("\tTest `search` completed\n");

  assert(linked_list_delete(&ll, "B") == 1);
  assert(linked_list_search(ll, "B") == 0);
  printf("\tTest `delete` completed\n");

  linked_list_append(&ll, "B");
  assert(linked_list_pop(&ll) == "B");
  assert(linked_list_pop(&ll) == "A");
  printf("\tTest `pop` completed\n");

  printf("Linked List Test Completed");
}