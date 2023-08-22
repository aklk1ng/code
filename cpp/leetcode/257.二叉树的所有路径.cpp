#include <algorithm>
#include <cmath>
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
  void traversal(TreeNode *cur, vector<int> &path, vector<string> &res) {
    path.push_back(cur->val); // 中
    if (!cur->left && !cur->right) {
      string spath;
      for (int i = 0; i < path.size() - 1; i++) {
        spath += to_string(path[i]);
        spath += "->";
      }
      spath += to_string(path[path.size() - 1]);
      res.push_back(spath);
    }

    // left
    if (cur->left) {
      traversal(cur->left, path, res);
      path.pop_back();
    }
    // right
    if (cur->right) {
      traversal(cur->right, path, res);
      path.pop_back();
    }
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    vector<int> path;
    if (!root)
      return res;
    traversal(root, path, res);
    return res;
  }
};

class Solution2 {
public:
  vector<string> res;

  void dfs(TreeNode *root, string path) {
    if (!root)
      return;
    path += to_string(root->val);
    if (!root->left && !root->right)
      res.push_back(path);
    else {
      path += "->";
      dfs(root->left, path);
      dfs(root->right, path);
    }
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    dfs(root, "");
    return res;
  }
};
