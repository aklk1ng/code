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
  vector<TreeNode *> res;
  unordered_set<int> s;
  TreeNode *dfs(TreeNode *root) {
    if (!root)
      return nullptr;
    root->left = dfs(root->left);
    root->right = dfs(root->right);
    if (!s.count(root->val))
      return root;

    if (root->left)
      res.push_back(root->left);
    if (root->right)
      res.push_back(root->right);
    return nullptr;
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    for (auto x : to_delete)
      s.insert(x);
    if (dfs(root))
      res.push_back(root);
    return res;
  }
};
