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

class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    if (!root)
      return true;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (!node)
          flag = true;
        else {
          if (flag)
            return false;
          q.push(node->left);
          q.push(node->right);
        }
      }
    }
    return true;
  }
};
