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
  // 返回一该节点的二叉树的高度, 如果不是平衡二叉树,则返回-1
  int getHeight(TreeNode *node) {
    if (!node)
      return 0;
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1)
      return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1)
      return -1;

    return abs(leftHeight - rightHeight) > 1 ? -1 : max(leftHeight, rightHeight) + 1;
  }
  bool isBalanced(TreeNode *root) { return getHeight(root) == -1 ? false : true; }
};

class Solution2 {
public:
  int getDepth(TreeNode *cur) {
    stack<TreeNode *> st;
    if (cur)
      st.push(cur);
    int depth = 0;
    int res = 0;
    while (!st.empty()) {
      TreeNode *node = st.top();
      if (node) {
        st.pop();
        st.push(node);
        st.push(NULL);
        depth++;

        if (node->right)
          st.push(node->right);
        if (node->left)
          st.push(node->left);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        depth--;
      }
      res = res > depth ? res : depth;
    }
    return res;
  }
  bool isBalanced(TreeNode *root) {
    stack<TreeNode *> st;
    if (!root)
      return true;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();

      if (abs(getDepth(node->left) - getDepth(node->right)) > 1)
        return false;
      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return true;
  }
};
