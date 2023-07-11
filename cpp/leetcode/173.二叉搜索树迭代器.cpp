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

class BSTIterator1 {
public:
  TreeNode *cur;
  stack<TreeNode *> st;

  BSTIterator1(TreeNode *root) : cur(root) {}

  int next() {
    while (cur) {
      st.push(cur);
      cur = cur->left;
    }

    cur = st.top();
    st.pop();
    int ret = cur->val;
    cur = cur->right;
    return ret;
  }

  bool hasNext() { return cur || !st.empty(); }
};

class BSTIterator2 {
public:
  vector<int> arr;
  int idx;

  void inorder(TreeNode *root, vector<int> &res) {
    if (!root)
      return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }

  vector<int> inorderTraverse(TreeNode *root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }

  BSTIterator2(TreeNode *root) : idx(0), arr(inorderTraverse(root)) {}

  int next() { return arr[idx++]; }

  bool hasNext() { return idx < arr.size(); }
};
