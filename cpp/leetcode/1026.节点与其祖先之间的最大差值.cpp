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
  int ans;
  void dfs(TreeNode *root, int mn, int mx) {
    if (!root) {
      ans = max(ans, mx - mn);
      return;
    }
    mn = min(mn, root->val);
    mx = max(mx, root->val);
    dfs(root->left, mn, mx);
    dfs(root->right, mn, mx);
  }
  int maxAncestorDiff(TreeNode *root) {
    dfs(root, root->val, root->val);
    return ans;
  }
};

class Solution2 {
public:
  int ans;
  pair<int, int> dfs(TreeNode *root) {
    if (!root) {
      return {INT_MAX, INT_MIN};
    }
    int mn = root->val, mx = mn;
    auto [l_mn, l_mx] = dfs(root->left);
    auto [r_mn, r_mx] = dfs(root->right);
    mn = min(mn, min(l_mn, r_mn));
    mx = max(mx, max(l_mx, r_mx));
    ans = max(ans, max(mx - root->val, root->val - mn));
    return {mn, mx};
  }
  int maxAncestorDiff(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
