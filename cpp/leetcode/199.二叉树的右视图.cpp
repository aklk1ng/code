#include <algorithm>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();
        if (i == (size - 1))
          res.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
    }
    return res;
  }
};
