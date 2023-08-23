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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (root)
      q.push(root);
    bool even = false;
    while (!q.empty()) {
      int sz = q.size();
      vector<int> v;
      while (sz--) {
        TreeNode *node = q.front();
        q.pop();
        v.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      if (even)
        reverse(v.begin(), v.end());
      even = !even;
      res.push_back(v);
    }
    return res;
  }
};
