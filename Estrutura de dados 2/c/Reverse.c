#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void Insert(int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
  temp->data = data;
  temp->next = head;
  head = temp;
}

void Print(struct Node *node) {
  if (node == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", node->data);
  Print(node->next);
}
void PrintReversed(struct Node *node) {
  if (node == NULL) {
    printf("\nNULL ");
    return;
  }
  PrintReversed(node->next);
  printf("-> %d ", node->data);
}

void ReverseIterative() {
  struct Node *current, *prev, *next;
  current = head;
  prev = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
void ReverseRecursion(struct Node *node) {
  if (node->next == NULL) {
    head = node;
    return;
  }
  ReverseRecursion(node->next);
  struct Node *p = node->next;
  p->next = node;
  node->next = NULL;
}

int main(int argc, char *argv[]) {
  head = NULL;
  Insert(4);
  Insert(3);
  Insert(2);
  Insert(1);
  Print(head);
  ReverseIterative();
  ReverseRecursion(head);
  Print(head);
  PrintReversed(head);
  return 0;
}
