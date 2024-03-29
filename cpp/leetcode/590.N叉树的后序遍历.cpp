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

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> postorder(Node *root) {
    vector<int> res;
    if (!root)
      return res;
    stack<Node *> st;
    st.push(root);
    while (!st.empty()) {
      Node *node = st.top();
      st.pop();
      res.push_back(node->val);
      for (int i = 0; i < node->children.size(); i++) {
        if (node->children[i])
          st.push(node->children[i]);
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
