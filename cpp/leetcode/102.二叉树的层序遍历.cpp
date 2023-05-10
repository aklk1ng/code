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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    vector<vector<int>> res;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      vector<int> vec;
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();
        vec.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      res.push_back(vec);
    }
    return res;
  }
};
