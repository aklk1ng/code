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
  int dfs(TreeNode *root, int max_val) {
    if (!root)
      return 0;
    int res = 0;
    if (root->val >= max_val) {
      res++;
      max_val = root->val;
    }
    res += dfs(root->left, max_val) + dfs(root, max_val);
    return res;
  }
  int goodNodes(TreeNode *root) { return dfs(root, INT_MIN); }
};
