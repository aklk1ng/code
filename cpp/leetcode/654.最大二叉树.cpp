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

class Soluton1 {
public:
  TreeNode *constructMaxinumBinaryTree(vector<int> &nums) {
    TreeNode *node = new TreeNode(0);
    if (nums.size() == 1) {
      node->val = nums[0];
      return node;
    }

    int maxvalue = INT_MIN;
    int maxvalueIndex = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > maxvalue) {
        maxvalue = nums[i];
        maxvalueIndex = i;
      }
    }
    node->val = maxvalue;

    if (maxvalueIndex > 0) {
      vector<int> v(nums.begin(), nums.begin() + maxvalueIndex);
      node->left = constructMaxinumBinaryTree(v);
    }

    if (maxvalueIndex < (nums.size() - 1)) {
      vector<int> v(nums.begin() + maxvalueIndex + 1, nums.end());
      node->right = constructMaxinumBinaryTree(v);
    }
    return node;
  }
};

class Soluton2 {
public:
  TreeNode *traversal(vector<int> &nums, int left, int right) {
    if (left > right)
      return nullptr;

    int maxvalueIndex = left;
    for (int i = left + 1; i <= right; i++) {
      if (nums[i] > nums[maxvalueIndex])
        maxvalueIndex = i;
    }

    TreeNode *root = new TreeNode(nums[maxvalueIndex]);

    root->left = traversal(nums, left, maxvalueIndex - 1);
    root->right = traversal(nums, maxvalueIndex + 1, right);

    return root;
  }
  TreeNode *constructMaxinumBinaryTree(vector<int> &nums) {
    return traversal(nums, 0, nums.size() - 1);
  }
};
