#ifndef doubly_linked_list_h
#define double_linked_list_h

struct Node {
  char* value;
  struct Node* prev;
  struct Node* next;
};

struct DoublyLL {
  int count;
  struct Node* root;
};

int append(struct Node** root, char* value);
int search(struct Node* root, char* value);
int delete (struct Node** root, char* value);
char* pop(struct Node** root);
void show(struct Node* root);
void test_doubly_linked_list();
#endif