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
  int maxCount = 0;
  int count = 0;
  TreeNode *pre = nullptr;
  vector<int> res;
  void searchBST(TreeNode *cur) {
    if (cur == nullptr)
      return;

    searchBST(cur->left);

    if (cur->val == pre->val)
      count++;
    else
      count = 1;
    pre = cur;

    if (count == maxCount)
      res.push_back(cur->val);
    if (count > maxCount) {
      maxCount = count;
      res.clear();
      res.push_back(cur->val);
    }

    searchBST(cur->right);
  }
  vector<int> findMode(TreeNode *root) {
    maxCount = 0;
    count = 0;
    pre = nullptr;
    res.clear();
    searchBST(root);
    return res;
  }
};
