#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
} Node;

Node *spawn(int key) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
int height(Node *node) {
  if (node == NULL) {
    return 0;
  }
  int heightLeft = height(node->left) + 1;
  int heightRight = height(node->right) + 1;
  if (heightLeft > heightRight) {
    return heightLeft;
  }
  return heightRight;
}

int balance(Node *node) { return height(node->left) - height(node->right); }

void prefixa(Node *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->key);
  prefixa(node->left);
  prefixa(node->right);
}

Node *rotRight(Node *node) {
  Node *new = node->left;
  node->left = new->right;
  new->right = node;
  return new;
}

Node *rotLeft(Node *node) {
  Node *new = node->right;
  node->right = new->left;
  new->left = node;
  return new;
}

Node *insert(Node *node, int key) {

  if (node == NULL) {
    node = spawn(key);
    return node;
  }
  if (node->key == key) {
    printf("\n Key %d already on tree. Operation terminated.\n", key);
    return node;
  }

  if (node->key > key) {
    node->left = insert(node->left, key);
  }
  if (node->key < key) {
    node->right = insert(node->right, key);
  }

  /*if (balance(node) > 1) {
    if (key < node->left->key) {
      printf("rotacao direita feita!");
      node = rotRight(node);
    }else {
      printf("rotacao esquerda e dps direita!");
      node->left = rotLeft(node->left);
      node = rotRight(node);
    }

  }
  if (balance(node) < 1) {
    if (key > node->right->key) {
      printf("rotacao esquerda feita!");
      node = rotLeft(node);
    }else {
      printf("rotacao direita e dps esquerda!");
      node->right = rotRight(node->right);
      node = rotLeft(node);
    }

  }*/
  return node;
}

int main(int argc, char *argv[]) {

  Node *root;
  root = insert(root, 6);
  root = insert(root, 10);
  root = insert(root, 11);

  prefixa(root);
  printf("%d", height(root));
  printf("%d", height(root->right));
  printf("%d", height(root->right->right));
  printf("%d", balance(root));

  root = rotRight(root);
  prefixa(root);

  return EXIT_SUCCESS;
}
