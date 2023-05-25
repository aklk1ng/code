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
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    // 减少一层递归的
    if (!root->left && !root->right)
      return 0;

    int lvalue = sumOfLeftLeaves(root->left); // 左
    if (root->left && !root->left->left && !root->left->right)
      lvalue = root->left->val;

    int rvalue = sumOfLeftLeaves(root->right); // 右

    return lvalue + rvalue; // 中
  }
};

class Soluton2 {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    stack<TreeNode *> st;
    if (!root)
      return 0;
    st.push(root);
    int res;
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node->left && !node->left->left && !node->left->right)
        res += node->left->val;

      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return res;
  }
};
