#include <algorithm>
#include <deque>
#include <limits.h>
#include <linux/limits.h>
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
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    queue<Node *> que;
    if (root)
      que.push(root);
    while (!que.empty()) {
      Node *pre;
      Node *node;
      int size = que.size();
      for (int i = 0; i < size; i++) {
        if (i == 0) {
          pre = que.front();
          que.pop();
          node = pre;
        } else {
          node = que.front();
          que.pop();
          pre->next = node;
          pre = pre->next;
        }
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      pre->next = NULL;
    }
    return root;
  }
};
