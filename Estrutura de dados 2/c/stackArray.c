
#include <stdio.h>
#define MAX_SIZE 101

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
  if (top == MAX_SIZE - 1) {
    printf("STACK OVERFLOW");
    return;
  }
  stack[top++] = value;
}

void pop() {
  if (top != -1) {
    top--;
  } else
    printf("\nnão há nada na pilha a ser retirado");
}

