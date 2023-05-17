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

class Soluton1 {
public:
  vector<int> res;
  vector<int> preorderTraversal(TreeNode *root) {
    if (root) {
      res.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }
    return res;
  }
};

class Soluton2 {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      res.push_back(node->val);
      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }
    return res;
  }
};
