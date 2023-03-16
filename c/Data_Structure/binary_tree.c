#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct TreeNode {
  DataType data;
  struct TreeNode *left;
  struct TreeNode *right;
} TNode;

TNode *CreateNode(DataType data) {
  TNode *node = (TNode *)malloc(sizeof(TNode));
  if (node == NULL) {
    printf("malloc falied\n");
    return NULL;
  }
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TNode *TreeInsert(TNode *root, DataType data) {
  if (root == NULL) {
    root = CreateNode(data);
  } else if (root->data > data) {
    root->left = TreeInsert(root->left, data);
  } else if (root->data < data) {
    root->right = TreeInsert(root->right, data);
  } else {
    printf("data has already exist!\n");
    exit(-1);
  }
  return root;
}

// 递归查找
TNode *TreeRecursionFind(TNode *root, DataType data) {
  if (root == NULL) {
    printf("the tree is empty!\n");
    return NULL;
  } else if (root->data > data) {
    return TreeRecursionFind(root->left, data);
  } else if (root->data < data) {
    return TreeRecursionFind(root->right, data);
  } else
    return root;
}

// 非递归查找
TNode *TreeIterationFind(TNode *root, DataType data) {
  TNode *node = root;
  while (node) {
    if (root->data > data) {
      node = node->left;
    } else if (root->data < data) {
      node = node->right;
    } else
      return node;
  }

  return NULL;
}

TNode *Find_Max(TNode *root) {
  if (root == NULL) {
    printf("the tree is empty!\n");
    return NULL;
  } else if (root->right) {
    return Find_Max(root->right);
  } else {
    return root;
  }
}

TNode *Find_Min(TNode *root) {
  if (root == NULL) {
    printf("the tree is empty!\n");
    return NULL;
  } else if (root->left) {
    return Find_Min(root->left);
  } else {
    return root;
  }
}

TNode *TreeDelete(TNode *root, DataType data) {
  if (root == NULL) {
    printf("the tree is empty!\n");
    return root;
  }
  TNode *tmp;
  if (root->data > data) {
    root->left = TreeDelete(root->left, data);
  } else if (root->data < data) {
    root->right = TreeDelete(root->right, data);
  } else if (root->data == data) { // found element to be deleted
    if (root->left && root->right) {
      tmp = Find_Min(root->right);
      root->data = tmp->data;
      root->right = TreeDelete(root, data);
    } else {
      tmp = root;
      if (root->left == NULL) {
        root = root->right;
      } else {
        root = root->left;
      }
      /* root = (root->left == NULL) ? root->right : root->left; */

      free(tmp);
    }
  } else
    printf("the element isn't existed!\n");
  return root;
}

// 先序遍历
void PreOrderTree(TNode *root) {
  if (root == NULL) {
    printf("NULL\n");
  } else {
    printf("%d ", root->data);
    PreOrderTree(root->left);
    PreOrderTree(root->right);
  }
}

// 中序遍历
void InOrderTree(TNode *root) {
  if (root == NULL) {
    printf("NULL\n");
  } else {
    InOrderTree(root->left);
    printf("%d ", root->data);
    InOrderTree(root->right);
  }
}

void test() {
  TNode *root = NULL;
  root = TreeInsert(root, 6);
  root = TreeInsert(root, 2);
  root = TreeInsert(root, 1);
  root = TreeInsert(root, 4);
  root = TreeInsert(root, 3);
  root = TreeInsert(root, 5);
  root = TreeInsert(root, 8);
  /* root = TreeDelete(root, 4); */
  TNode *tmp = Find_Max(root);
  printf("max:%d\n", tmp->data);
  tmp = Find_Min(root);
  printf("min:%d\n", tmp->data);
  InOrderTree(root);
  printf("--------------------\n");
  PreOrderTree(root);
}

int main(int argc, char const *argv[]) {
  test();
  return 0;
}
