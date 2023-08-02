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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val);
      if (node->left)
        st.push(node->left);
      if (node->right)
        st.push(node->right);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
