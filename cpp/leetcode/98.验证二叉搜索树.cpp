#include <algorithm>
#include <deque>
#include <limits.h>
#include <map>
#include <pthread.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
  vector<int> res;
  void inorder(TreeNode *node) {
    if (node) {
      inorder(node->left);
      res.push_back(node->val);
      inorder(node->right);
    }
  }
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    inorder(root);
    for (int i = 1; i < res.size(); i++) {
      if (res[i] <= res[i - 1])
        return false;
    }
    return true;
  }
};
