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
    if (!left && !right)
      return false;
    if (!left || !right || left->val != right->val)
      return false;
    return compare(left->left, right->right) && compare(left->right, right->left);
  }
  bool isSymetric(TreeNode *root) { return compare(root->left, root->right); }
};
