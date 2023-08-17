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
  TreeNode *reConstructBinaryTree(vector<int> &preOrder, vector<int> &vinOrder) {
    int n = preOrder.size();
    int m = vinOrder.size();
    if (n == 0 || m == 0)
      return nullptr;

    stack<TreeNode *> s;
    TreeNode *root = new TreeNode(preOrder[0]);
    TreeNode *cur = root;

    for (int i = 1, j = 0; i < n; i++) {
      if (cur->val != vinOrder[j]) {
        cur->left = new TreeNode(preOrder[i]);
        s.push(cur);
        cur = cur->left;
      } else {
        j++;
        while (!s.empty() && s.top()->val == vinOrder[j]) {
          cur = s.top();
          s.pop();
          j++;
        }
        cur->right = new TreeNode(preOrder[i]);
        cur = cur->right;
      }
    }

    return root;
  }
};
