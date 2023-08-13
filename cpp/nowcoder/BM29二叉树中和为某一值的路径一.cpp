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
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root)
      return false;
    return dfs(root, sum);
  }

  bool dfs(TreeNode *node, int target) {
    if (!node)
      return false;
    target -= node->val;
    if (!node->left && !node->right && target == 0)
      return true;

    return dfs(node->left, target) || dfs(node->right, target);
  }
};
