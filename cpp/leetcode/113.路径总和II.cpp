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
  vector<vector<int>> res;
  vector<int> path;
  void dfs(TreeNode *root, int targetSum) {
    if (!root)
      return;
    targetSum -= root->val;
    if (!root->left && !root->right && targetSum == 0)
      res.emplace_back(path);

    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    path.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    dfs(root, targetSum);
    return res;
  }
};
