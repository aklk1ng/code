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

class Solution1 {
public:
  TreeNode *invertTree(TreeNode *root) {
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();
        swap(node->left, node->right);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return root;
  }
};

class Solution2 {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

class Solution3 {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};
