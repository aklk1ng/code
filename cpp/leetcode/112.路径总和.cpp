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
  bool traversal(TreeNode *root, int count) {
    if (!root->left && !root->right && count == 0)
      return true;
    if (!root->left && !root->right)
      return false;

    if (root->left)
      if (traversal(root->left, count - root->left->val))
        return true;

    if (root->right)
      if (traversal(root->right, count - root->right->val))
        return true;

    return false;
  }
  bool haspathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;
    return traversal(root, targetSum - root->val);
  }
};

class Soluton2 {
public:
  bool haspathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;
    stack<pair<TreeNode *, int>> st;
    st.push(pair<TreeNode *, int>(root, root->val));
    while (!st.empty()) {
      pair<TreeNode *, int> node = st.top();
      st.pop();

      if (!node.first->left && !node.first->right && targetSum == node.second)
        return true;

      if (node.first->right)
        st.push(pair<TreeNode *, int>(node.first->right, node.second + node.first->right->val));
      if (node.first->left)
        st.push(pair<TreeNode *, int>(node.first->left, node.second + node.first->left->val));
    }
    return false;
  }
};
