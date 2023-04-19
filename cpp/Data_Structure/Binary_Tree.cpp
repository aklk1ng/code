#include <iostream>
using namespace std;

typedef int ElementType;

class Binary_Tree {
public:
  struct Node {
    ElementType val;
    Node *left;
    Node *right;
    Node(ElementType x) : val(x), left(nullptr), right(nullptr) {}
  };
  Binary_Tree(ElementType x) { root = new Node(x); }

  Node *TreeInsert(Node *root, ElementType x) {
    if (root == nullptr) {
      root = new Node(x);
    } else if (root->val > x) {
      root->left = TreeInsert(root->left, x);
    } else if (root->val < x) {
      root->right = TreeInsert(root->right, x);
    } else {
      cout << "have same node data" << endl;
    }
    return root;
  }

  Node *TreeFind(Node *root, ElementType x) {
    if (root == nullptr) {
      cout << "the tree is empty" << endl;
      return nullptr;
    } else if (root->val > x) {
      return TreeFind(root->left, x);
    } else if (root->val < x) {
      return TreeFind(root->right, x);
    } else
      return root;
  }

  Node *Find_Max(Node *root) {
    if (root == nullptr) {
      cout << "the tree is empty" << endl;
      return nullptr;
    } else if (root->right) {
      return Find_Max(root->right);
    } else {
      return root;
    }
  }

  Node *Find_Min(Node *root) {
    if (root == nullptr) {
      cout << "the tree is empty" << endl;
      return nullptr;
    } else if (root->left) {
      return Find_Min(root->left);
    } else {
      return root;
    }
  }

  void PreOrderTree(Node *root) {
    if (root == nullptr) {
      cout << "nullptr" << endl;
    } else {
      cout << root->val << endl;
      PreOrderTree(root->left);
      PreOrderTree(root->right);
    }
  }
  void InOrderTree(Node *root) {
    if (root == nullptr) {
      cout << "nullptr" << endl;
    } else {
      InOrderTree(root->left);
      cout << root->val << endl;
      InOrderTree(root->right);
    }
  }

  Node *TreeDelete(Node *root, ElementType x) {
    if (root == nullptr) {
      cout << "the tree is empty" << endl;
      return nullptr;
    }
    Node *tmp;
    if (root->val > x) {
      root->left = TreeDelete(root->left, x);
    } else if (root->val < x) {
      root->right = TreeDelete(root->right, x);
    } else if (root->val == x) {
      if (root->left && root->right) {
        tmp = Find_Min(root->right);
        root->val = tmp->val;
        root->right = TreeDelete(root, x);
      } else {
        tmp = root;
        if (root->left == nullptr)
          root = root->right;
        else
          root = root->left;
        delete tmp;
      }
    } else
      cout << "no this value" << endl;
    return root;
  }

  Node *root;
};

void test() {
  Binary_Tree b(0);
  b.TreeInsert(b.root, -1);
  b.TreeInsert(b.root, 2);
  b.TreeInsert(b.root, 3);
  b.InOrderTree(b.root);
  Binary_Tree::Node *max = b.Find_Max(b.root);
  cout << max->val << endl;
  Binary_Tree::Node *min = b.Find_Min(b.root);
  cout << min->val << endl;
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
