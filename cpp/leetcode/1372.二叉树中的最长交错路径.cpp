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
  vector<int> dfs(TreeNode *root) {
    if (!root)
      return vector<int>{-1, -1};

    int lr = dfs(root->left)[1] + 1;
    int rl = dfs(root->right)[0] + 1;
    ans = max(ans, max(lr, rl));

    return vector<int>{lr, rl};
  }
  int longestZigzag(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
