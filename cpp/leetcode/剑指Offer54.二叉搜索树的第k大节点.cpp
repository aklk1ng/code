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

class Soluton {
public:
  vector<int> res;
  void traverse(TreeNode *root) {
    if (root) {
      traverse(root->left);
      res.push_back(root->val);
      traverse(root->right);
    }
  }
  int kthLargest(TreeNode *root, int k) {
    if (!root)
      return -1;
    traverse(root);
    return res[res.size() - k];
  }
};
