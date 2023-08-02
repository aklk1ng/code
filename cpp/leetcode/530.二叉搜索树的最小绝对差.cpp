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
  vector<int> v;
  void traversal(TreeNode *root) {
    if (root) {
      traversal(root->left);
      v.push_back(root->val);
      traversal(root->right);
    }
  }
  int getMinimumDifference(TreeNode *root) {
    int res = INT_MAX;
    traversal(root);
    if (v.size() < 2)
      return 0;
    for (int i = 0; i < v.size() - 1; i++) {
      res = min(res, v[i + 1] - v[i]);
    }
    return res;
  }
};
