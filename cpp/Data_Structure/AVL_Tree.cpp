#include <algorithm>
#include <cmath>
#include <iostream>

typedef int ElementType;

class AVL_Tree {
public:
  struct Node {
    ElementType val;
    Node *left;
    Node *right;
    int height;

    Node(ElementType val)
        : val(val), left(nullptr), right(nullptr), height(0) {}
  };

  AVL_Tree(ElementType x) { root = new Node(x); }

  ~AVL_Tree() { delete this->root; }

  Node *SingleRotateWithLeft(Node *k2) {
    Node *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = 1 + std::max(Tree_Height(k2->left), Tree_Height(k2->right));
    k1->height = 1 + std::max(Tree_Height(k1->left), Tree_Height(k1->right));
    return k1;
  }

  Node *DoubleRotateWithLeft(Node *k3) {
    k3->left = SingleRotateWithLeft(k3->left);
    return SingleRotateWithLeft(k3);
  }

  Node *SingleRotateWithRight(Node *k1) {
    Node *k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k2->height = 1 + std::max(Tree_Height(k2->left), Tree_Height(k2->right));
    k1->height = 1 + std::max(Tree_Height(k1->left), Tree_Height(k1->right));
    return k2;
  }

  Node *Insert(Node *root, ElementType x) {
    if (root == nullptr)
      root = new Node(x);
    else if (root->val > x) {
      root->left = Insert(root->left, x);
      if (Tree_Height(root->left) - Tree_Height(root->right) == 2) {
        if (x < root->left->val)
          root = SingleRotateWithLeft(root);
        else
          root = DoubleRotateWithLeft(root);
      }
    } else if (root->val < x) {
      root->right = Insert(root->right, x);
      if (Tree_Height(root->right) - Tree_Height(root->left) == 2) {
        if (x > root->right->val)
          root = SingleRotateWithRight(root);
        else
          root = DoubleRotateWithRight(root);
      }
    }

    root->height =
        1 + std::max(Tree_Height(root->left), Tree_Height(root->right));
    return root;
  }

  Node *DoubleRotateWithRight(Node *k3) {
    k3->right = SingleRotateWithLeft(k3->right);
    return SingleRotateWithLeft(k3);
  }

  int Get_Node_Height(Node *node) {
    if (node == nullptr)
      return 0;
    else
      return node->height;
  }

  int Tree_Height(Node *root) {
    if (!root)
      return 0;
    int leftHeight = Tree_Height(root->left);
    if (leftHeight == -1)
      return -1;
    int rightHeight = Tree_Height(root->right);
    if (rightHeight == -1)
      return -1;

    return abs(leftHeight - rightHeight) > 1
               ? -1
               : std::max(leftHeight, rightHeight) + 1;
  }

  bool isBalanced(Node *root) {
    return this->Tree_Height(root) == -1 ? false : true;
  }

  Node *FindMax(Node *root) {
    if (root == nullptr) {
      std::cout << "the tree is empty!" << std::endl;
      return nullptr;
    } else if (root->right) {
      return FindMax(root->right);
    } else
      return root;
  }

  Node *FindMin(Node *root) {
    if (root == nullptr) {
      std::cout << "the tree is empty!" << std::endl;
      return nullptr;
    } else if (root->left) {
      return FindMin(root->left);
    } else
      return root;
  }

  void InOrderTree(Node *root) {
    if (root) {
      InOrderTree(root->left);
      std::cout << root->val << std::endl;
      InOrderTree(root->right);
    }
  }

  Node *root;
};

void test() {
  AVL_Tree t(0);
  t.Insert(t.root, -1);
  t.Insert(t.root, 1);
  t.Insert(t.root, 2);
  t.Insert(t.root, -2);
  t.InOrderTree(t.root);

  std::cout << "---------------------" << std::endl;
  std::cout << t.FindMax(t.root)->val << std::endl;
  std::cout << t.Tree_Height(t.root) << std::endl;
  std::cout << t.isBalanced(t.root) << std::endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
