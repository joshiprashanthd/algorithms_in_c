#ifndef linked_list_h
#define linked_list_h

struct LinkedListNode {
  char* value;
  struct LinkedListNode* next;
};

struct LinkedList {
  int count;
  struct LinkedListNode* root;
};

struct LinkedList* linked_list_new();
int linked_list_append(struct LinkedList** linked_list, char* value);
int linked_list_search(struct LinkedList* linked_list, char* value);
int linked_list_delete(struct LinkedList** linked_list, char* value);
char* linked_list_pop(struct LinkedList** linked_list);
void linked_list_show(struct LinkedList* linked_list);
void test_linked_list();
#endif