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
  vector<TreeNode *> res;
  void inOrder(TreeNode *root) {
    if (!root)
      return;
    inOrder(root->left);
    res.push_back(root);
    inOrder(root->right);
  }
  TreeNode *Convert(TreeNode *pRootOfTree) {
    if (!pRootOfTree)
      return pRootOfTree;
    inOrder(pRootOfTree);
    for (int i = 0; i < res.size() - 1; i++) {
      res[i]->right = res[i + 1];
      res[i + 1]->left = res[i];
    }
    return res[0];
  }
};

class Solution2 {
public:
  TreeNode *preNode;
  void inOrder(TreeNode *root) {
    if (!root)
      return;
    inOrder(root->left);
    root->left = preNode;
    if (preNode)
      preNode->right = root;
    preNode = root;
    inOrder(root->right);
  }
  TreeNode *Convert(TreeNode *pRootOfTree) {
    if (!pRootOfTree)
      return pRootOfTree;
    TreeNode *p = pRootOfTree;
    while (p->left)
      p = p->left;
    inOrder(pRootOfTree);
    return p;
  }
};
