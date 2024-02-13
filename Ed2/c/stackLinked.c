
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void push(int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
  temp->data = data;
  temp->next = head;
  head = temp;
}

void pop() {
  if (head == NULL) {
    printf("\nempty list");
    return;
  }
  head = head->next;
}

