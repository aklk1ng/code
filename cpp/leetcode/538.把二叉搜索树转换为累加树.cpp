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
  int pre = 0;
  void traversal(TreeNode *cur) {
    if (!cur)
      return;

    traversal(cur->right);
    cur->val += pre;
    pre = cur->val;
    traversal(cur->left);
  }
  TreeNode *convertBST(TreeNode *root) {
    pre = 0;
    traversal(root);
    return root;
  }
};
