#include <stdio.h>
#include <stdlib.h>

/*  Cost of acessing an element:
 *  Array: O(1)
 *  Linked list: O(n)
 *
 *  Memory usage:
 *  Array: -Fixed size,
 *  LInked list: No unused memory, extra memory for storing pointers (Best to
 * use with bigger variables)
 *
 *  Inserting
 *  Array:       Beggining O(n) | At end 0(1) if array not full, else 0(n)| In n
 * position O(n) Linked list:           O(1) |       0(n) |               O(n)
 */

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void InsertAtStart(int x, struct Node *temp) {
  temp->data = x;
  temp->next = head;
  head = temp;
}

void Insert(int data, int pos) {
  struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node *));

  if (pos == 0) {
    InsertAtStart(data, temp1);
    return;
  }

  temp1->data = data;
  temp1->next = NULL;

  struct Node *temp2 = head;

  for (int i = 0; i < pos - 1; i++) {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Delete(int pos) {

  struct Node *temp1 = head;

  if (pos == 1) {
    head = temp1->next;
    free(temp1);
    return;
  }

  for (int i = 0; i < pos - 1; i++)
    temp1 = temp1->next;
  struct Node *temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
}

void Print() {
  struct Node *node = head;
  while (node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf(" NULL\n");
}

int main(int argc, char *argv[]) {
  head = NULL; // empty

  Insert(2, 0);
  Insert(3, 0);
  Insert(4, 1);
  Insert(5, 3);
  Print();
  Delete(2);
  Print();
  return 0;
}
