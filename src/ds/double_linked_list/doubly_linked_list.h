#ifndef doubly_linked_list_h
#define double_linked_list_h

struct DoublyLinkedListNode {
  char* value;
  struct DoublyLinkedListNode* prev;
  struct DoublyLinkedListNode* next;
};

struct DoublyLinkedList {
  int count;
  struct DoublyLinkedListNode* root;
};

struct DoublyLinkedList* doubly_linked_list_new();
int doubly_linked_list_append(struct DoublyLinkedList** doubly_ll, char* value);
int doubly_linked_list_search(struct DoublyLinkedList* doubly_ll, char* value);
int doubly_linked_list_delete(struct DoublyLinkedList** doubly_ll, char* value);
char* doubly_linked_list_pop(struct DoublyLinkedList** doubly_ll);
void doubly_linked_list_show(struct DoublyLinkedList* doubly_ll);
void test_doubly_linked_list();
#endif