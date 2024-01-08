#include <stdio.h>
#include <stdlib.h>

/*  Cost of acessing an element: 
 *  Array: O(1)
 *  Linked list: O(n) 
 *
 *  Memory usage:
 *  Array: -Fixed size, 
 *  LInked list: No unused memory, extra memory for storing pointers (Best to use with bigger variables)
 *  
 *  Inserting
 *  Array:       Beggining O(n) | At end 0(1) if array not full, else 0(n)| In n position O(n)
 *  Linked list:           O(1) |       0(n)                              |               O(n)
 */

struct Node {
    int data;
    struct Node *next;
};

struct Node* head;

void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp -> data = x; 
    temp -> next = head;
    head = temp;
}
void Print(){
    struct Node* node = head;
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf(" NULL\n");
}

int main(int argc, char *argv[]) {
    head = NULL; // empty
    
    Insert(3);
    Print();
    Insert(5);
    Print();
    Insert(7);
    Print();
    Insert(9);
    Print();
    return 0;
}
