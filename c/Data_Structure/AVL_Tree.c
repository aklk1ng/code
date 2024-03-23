#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TNode {
  ElementType data;
  struct TNode *left;
  struct TNode *right;
  int height;
} TNode;

int Max(int left, int right) { return left > right ? left : right; }

int Get_Node_Height(TNode *node) {
  if (node == NULL) {
    return 0;
  } else
    return node->height;
}

int TotalHeight(TNode *root) {
  if (root == NULL) {
    return -1;
  } else {
    return 1 + Max(TotalHeight(root->left), TotalHeight(root->right));
  }
}

TNode *CreateNode(ElementType x) {
  TNode *node = (TNode *)malloc(sizeof(TNode));
  if (node == NULL) {
    printf("malloc failed!\n");
    exit(-1);
  }
  node->data = x;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  return node;
}

TNode *SingleRotateWithLeft(TNode *k2) {
  TNode *k1;
  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k2->height = 1 + Max(TotalHeight(k2->left), TotalHeight(k2->right));
  k1->height = 1 + Max(TotalHeight(k1->left), TotalHeight(k1->right));
  return k1;
}

TNode *DoubleRotateWithLeft(TNode *k3) {
  k3->left = SingleRotateWithLeft(k3->left);
  return SingleRotateWithLeft(k3);
}

TNode *SingleRotateWithRight(TNode *k1) {
  TNode *k2;
  k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;

  k2->height = 1 + Max(TotalHeight(k2->left), TotalHeight(k2->right));
  k1->height = 1 + Max(TotalHeight(k1->left), TotalHeight(k1->right));
  return k2;
}

TNode *DoubleRotateWithRight(TNode *k3) {
  k3->right = SingleRotateWithRight(k3->right);
  return SingleRotateWithRight(k3);
}

TNode *Insert(TNode *root, ElementType x) {
  if (root == NULL) {
    root = CreateNode(x);
  } else if (x < root->data) {
    root->left = Insert(root->left, x);
    if (TotalHeight(root->left) - TotalHeight(root->right) == 2) {
      if (x < root->left->data) {
        root = SingleRotateWithLeft(root);
      } else {
        root = DoubleRotateWithLeft(root);
      }
    }
  } else if (x > root->data) {
    root->right = Insert(root->right, x);
    if (TotalHeight(root->right) - TotalHeight(root->left) == 2) {
      if (x > root->right->data) {
        root = SingleRotateWithRight(root);
      } else {
        root = DoubleRotateWithRight(root);
      }
    }
  }

  root->height = 1 + Max(TotalHeight(root->left), TotalHeight(root->right));
  return root;
}

TNode *FindMin(TNode *root) {
  if (root == NULL) {
    printf("the tree is empty!\n");
    return NULL;
  } else if (root->left) {
    return FindMin(root->left);
  } else {
    return root;
  }
}

TNode *FindMax(TNode *root) {
  if (root == NULL) {
    printf("the tree is empty!\n");
    return NULL;
  } else if (root->right) {
    return FindMax(root->right);
  } else
    return root;
}

void InOrderTree(TNode *root) {
  if (root) {
    InOrderTree(root->left);
    printf("%d\n", root->data);
    InOrderTree(root->right);
  }
}

void test() {
  TNode *root = NULL;
  root = Insert(root, 2);
  root = Insert(root, 1);
  root = Insert(root, 3);
  root = Insert(root, 4);
  root = Insert(root, 5);
  root = Insert(root, 6);
  printf("data:%d\n", root->data);
  printf("%d\n", TotalHeight(root));
  InOrderTree(root);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
