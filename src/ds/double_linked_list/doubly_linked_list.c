#include "doubly_linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct DoublyLinkedList* doubly_linked_list_new() {
  struct DoublyLinkedList* doubly_ll =
      (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
  doubly_ll->count = 0;
  doubly_ll->root = NULL;
  return doubly_ll;
}

int doubly_linked_list_append(struct DoublyLinkedList** doubly_ll,
                              char* value) {
  if (value == NULL) return 0;

  struct DoublyLinkedListNode* new_node =
      (struct DoublyLinkedListNode*)malloc(sizeof(struct DoublyLinkedListNode));
  new_node->value = value;

  if ((*doubly_ll)->root == NULL)
    (*doubly_ll)->root = new_node;
  else {
    struct DoublyLinkedListNode* temp = (*doubly_ll)->root;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
  }

  return 1;
}

int doubly_linked_list_search(struct DoublyLinkedList* doubly_ll, char* value) {
  struct DoublyLinkedListNode* temp = doubly_ll->root;

  while (temp != NULL) {
    if (temp->value == value) return 1;
    temp = temp->next;
  }

  return 0;
}

int doubly_linked_list_delete(struct DoublyLinkedList** doubly_ll,
                              char* value) {
  if (value == NULL) return 0;
  if ((*doubly_ll)->root == NULL) return 0;

  struct DoublyLinkedListNode* temp = (*doubly_ll)->root;

  if (temp->value == value) {
    if (temp->next != NULL) {
      (temp->next)->prev = NULL;
      (*doubly_ll)->root = temp->next;
    }

    free(temp);
    return 1;
  }

  while (temp->next != NULL && (temp->next)->value != value) temp = temp->next;

  // cannot find node with value `value`
  if (temp->next == NULL) return 0;

  struct DoublyLinkedListNode* target = temp->next;
  temp->next = target->next;
  (temp->next)->prev = temp;
  free(target);

  return 1;
}

char* doubly_linked_list_pop(struct DoublyLinkedList** doubly_ll) {
  if ((*doubly_ll)->root == NULL) return 0;

  struct DoublyLinkedListNode* temp = (*doubly_ll)->root;
  while (temp->next != NULL) temp = temp->next;

  char* target_value = temp->value;
  if (temp->prev) (temp->prev)->next = NULL;
  free(temp);

  return target_value;
}

void test_doubly_linked_list() {
  printf("\n\nDoubly Linked List Test Started:\n");

  struct DoublyLinkedList* doubly_ll = doubly_linked_list_new();

  assert(doubly_linked_list_append(&doubly_ll, "A") == 1);
  assert(doubly_linked_list_append(&doubly_ll, "B") == 1);
  assert(doubly_linked_list_append(&doubly_ll, "D") == 1);
  printf("\tTest `append` completed\n");

  assert(doubly_linked_list_search(doubly_ll, "A") == 1);
  assert(doubly_linked_list_search(doubly_ll, "C") == 0);
  printf("\tTest `search` completed\n");

  assert(doubly_linked_list_delete(&doubly_ll, "B") == 1);
  assert(doubly_linked_list_search(doubly_ll, "B") == 0);

  assert(doubly_linked_list_delete(&doubly_ll, "A") == 1);
  assert(doubly_linked_list_search(doubly_ll, "A") == 0);

  assert(doubly_linked_list_delete(&doubly_ll, "B") == 0);
  printf("\tTest `delete` completed\n");

  assert(doubly_linked_list_pop(&doubly_ll) == "D");
  printf("\tTest `pop` completed\n");

  printf("Doublu Linked List Test Completed\n");
}