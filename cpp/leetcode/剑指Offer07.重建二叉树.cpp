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
  // pos 记录 inorder 每个节点的位置
  unordered_map<int, int> pos;
  TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
    if (pl > pr)
      return nullptr;
    // 根节点在 inorder 中的位置(分割左右子树)
    int k = pos[preorder[pl]] - il;
    auto root = new TreeNode(preorder[pl]);
    root->left = dfs(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
    root->right = dfs(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; i++)
      pos[inorder[i]] = i;

    return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};
