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
  int dfs(TreeNode *root, int res) {
    if (!root)
      return 0;
    res = res * 10 + root->val;
    if (!root->left && !root->right)
      return res;
    else {
      return dfs(root->left, res) + dfs(root->right, res);
    }
  }
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};

class Solution2 {
public:
  int res;
  long long sum;
  void dfs(TreeNode *root, int sum) {
    if (!root)
      return;
    sum += root->val;
    if (!root->left && !root->right)
      res += sum;
    dfs(root->left, (long long)sum * 10);
    dfs(root->right, (long long)sum * 10);
  }
  int sumNumbers(TreeNode *root) {
    dfs(root, 0);
    return res;
  }
};
