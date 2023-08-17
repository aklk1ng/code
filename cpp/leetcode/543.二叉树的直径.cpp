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
  int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node)
        return -1;
      int l_len = dfs(node->left);
      int r_len = dfs(node->right);
      ans = max(ans, l_len + r_len + 2);
      return max(l_len, r_len) + 1;
    };
    dfs(root);

    return ans;
  }
};
