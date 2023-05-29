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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return nullptr;

    if (root->val == key) {
      // no children
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->left && root->right == nullptr) { // left children
        TreeNode *ret = root->left;
        delete root;
        return ret;
      } else if (root->left == nullptr && root->right) { // right children
        TreeNode *ret = root->right;
        delete root;
        return ret;
      } else { // two children
        TreeNode *cur = root->right;
        while (cur->left)
          cur = cur->left;

        cur->left = root->left;
        TreeNode *tmp = root;
        root = root->right;
        delete tmp;
        return root;
      }
    }

    if (root->val > key)
      root->left = deleteNode(root->left, key);
    if (root->val < key)
      root->right = deleteNode(root->right, key);
    return root;
  }
};
