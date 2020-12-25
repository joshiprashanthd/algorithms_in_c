#ifndef linked_list_h
#define linked_list_h

struct Node {
  char* value;
  struct Node* next;
};

struct LinkedList {
  int count;
  struct Node* base_node;
};

int insert(struct Node** base_node, char* value);
int search(struct Node* base_node, char* value);
int delete (struct Node** base_node, char* value);
void show(struct Node* base_node);
void test_linked_list();
#endif