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

/*
 * 回溯
 */
class Soluton1 {
public:
  int res;
  int maxDepth = INT_MIN;
  void traversal(TreeNode *root, int depth) {
    if (!root->left && !root->right) {
      if (depth > maxDepth) {
        maxDepth = depth;
        res = root->val;
        return;
      }
    }

    if (root->left) {
      depth++;
      traversal(root->left, depth);
      depth--;
    }

    if (root->right) {
      depth++;
      traversal(root->right, depth);
      depth--;
    }

    return;
  }
  int findBottomLeftLeaves(TreeNode *root) {
    traversal(root, 0);
    return res;
  }
};

/*
 * bfs
 * 在遍历一个节点时，需要先把它的非空右子节点放入队列，然后再把它的非空左子节点放入队列，这样才能保证从右到左遍历每一层的节点。
 * 广度优先搜索所遍历的最后一个节点的值就是最底层最左边节点的值。
 */
class Soluton2 {
public:
  int findBottomLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    int res;
    q.push(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (node->right)
        q.push(node->right);
      if (node->left)
        q.push(node->left);
      res = node->val;
    }
    return res;
  }
};
