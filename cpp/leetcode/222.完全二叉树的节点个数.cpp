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

class Solution1 {
public:
  int countNodes(TreeNode *root) {
    queue<TreeNode *> que;
    int count = 0;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();
        count++;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return count;
  }
};

class Solution2 {
public:
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth, rightDepth = 0;
    while (left) {
      left = left->left;
      leftDepth++;
    }
    while (right) {
      right = right->right;
      rightDepth++;
    }
    if (leftDepth == rightDepth)
      return (2 << leftDepth) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
