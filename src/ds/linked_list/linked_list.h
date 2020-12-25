#ifndef linked_list_h
#define linked_list_h

struct Node {
  char* value;
  struct Node* next;
};

struct LinkedList {
  int count;
  struct Node* root;
};

int insert(struct Node** root, char* value);
int search(struct Node* root, char* value);
int delete (struct Node** root, char* value);
void show(struct Node* root);
void test_linked_list();
#endif