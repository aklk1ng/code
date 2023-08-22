#include <algorithm>
#include <deque>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> que;
    que.push(root);
    int depth = 0;
    while (!que.empty()) {
      int size = que.size();
      depth++;
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();

        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
        if (!node->left && !node->right)
          return depth;
      }
    }
    return depth;
  }
};

class Solution2 {
public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    if (!root->left && !root->right)
      return 1;
    int min_depth = INT_MAX;
    if (root->left)
      min_depth = min(minDepth(root->left), min_depth);
    if (root->right)
      min_depth = min(minDepth(root->right), min_depth);
    return min_depth + 1;
  }
};
