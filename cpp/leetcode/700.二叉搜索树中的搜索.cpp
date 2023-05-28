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

class Soluton1 {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root || root->val == val)
      return root;
    TreeNode *res;
    if (root->val > val)
      res = searchBST(root->left, val);
    if (root->val < val)
      res = searchBST(root->right, val);
    return res;
  }
};

class Soluton2 {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root) {
      if (root->val > val)
        root = root->left;
      else if (root->val < val)
        root = root->right;
      else
        return root;
    }
    return nullptr;
  }
};
