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

class Node {
public:
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val) { val = _val; }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    queue<Node *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      int size = que.size();
      vector<int> vec;
      for (int i = 0; i < size; i++) {
        Node *node = que.front();
        que.pop();
        vec.push_back(node->val);
        for (int j = 0; j < node->children.size(); j++)
          if (node->children[i])
            que.push(node->children[i]);
      }
      res.push_back(vec);
    }
    return res;
  }
};
