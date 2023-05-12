#include <algorithm>
#include <deque>
#include <limits.h>
#include <map>
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
  bool compare(TreeNode *left, TreeNode *right) {
    if (left != NULL && right == NULL)
      return false;
    else if (left == NULL && right != NULL)
      return false;
    else if (left == NULL && right == NULL)
      return true;
    else if (left->val != right->val)
      return false;

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    bool issame = outside && inside;
    return issame;
  }
  bool isSymetric(TreeNode *root) {
    if (!root)
      return true;
    return compare(root->left, root->right);
  }
};
