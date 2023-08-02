#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  Node *pre;
  Node *head;
  void dfs(Node *node) {
    if (!node)
      return;
    dfs(node->left);
    if (pre)
      pre->right = node;
    else
      head = node;
    node->left = pre;
    pre = node;
    dfs(node->right);
  }

public:
  Node *treeDoublyList(Node *root) {
    if (!root)
      return NULL;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
  }
};
