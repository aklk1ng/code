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
  string tree2str(TreeNode *root) {
    if (!root)
      return "";
    else if (!root->left && !root->right)
      return to_string(root->val);
    else if (root->left && !root->right)
      return to_string(root->val) + "(" + tree2str(root->left) + ")";
    else
      return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
  }
};
