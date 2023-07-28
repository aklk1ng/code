#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Soluton1 {
public:
  int sum = 0;
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root)
      return 0;
    rangeSumBST(root->left, low, high);
    rangeSumBST(root->right, low, high);
    if (root->val <= high && root->val >= low)
      sum += root->val;
    return sum;
  }
};

class Soluton2 {
public:
  int sum = 0;
  int rangeSumBST(TreeNode *root, int low, int high) {
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      while (size--) {
        TreeNode *node = que.front();
        que.pop();
        if (node->val <= high && node->val >= low)
          sum += node->val;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return sum;
  }
};
