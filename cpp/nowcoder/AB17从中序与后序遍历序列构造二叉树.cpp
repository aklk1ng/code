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
  int post_pos;
  unordered_map<int, int> mp;
  TreeNode *BuildTree(vector<int> &inorder, vector<int> &postorder, int left, int right) {
    if (left > right)
      return nullptr;
    int val = postorder[post_pos];
    int idx = mp[val];
    TreeNode *root = new TreeNode(val);

    post_pos--;
    root->right = BuildTree(inorder, postorder, idx + 1, right);
    root->left = BuildTree(inorder, postorder, left, idx - 1);
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty())
      return nullptr;
    post_pos = postorder.size() - 1;
    for (int i = 0; i < inorder.size(); i++)
      mp[inorder[i]] = i;
    return BuildTree(inorder, postorder, 0, post_pos);
  }
};
