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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;
    queue<TreeNode *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      double sum = 0;
      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();
        sum += node->val;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      res.push_back(sum / size);
    }
    return res;
  }
};
