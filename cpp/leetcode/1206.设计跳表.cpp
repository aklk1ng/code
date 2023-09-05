#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_LEVEL = 32;
constexpr double P_FACTOR = 0.25;

struct Node {
  int val;
  vector<Node *> forward;
  Node(int _val, int _maxlevel = MAX_LEVEL) : val(_val), forward(_maxlevel, nullptr) {}
};

class Skiplist {
private:
  Node *head;
  int level;
  mt19937 gen{random_device{}()};
  uniform_real_distribution<double> dis;

public:
  Skiplist() : head(new Node(-1)), level(0), dis(0, 1) {}

  bool search(int target) {
    Node *cur = this->head;
    for (int i = level - 1; i >= 0; i--) {
      while (cur->forward[i] && cur->forward[i]->val < target)
        cur = cur->forward[i];
    }
    cur = cur->forward[0];
    if (cur && cur->val == target)
      return true;
    return false;
  }

  void add(int num) {
    vector<Node *> update(MAX_LEVEL, head);
    Node *cur = this->head;
    for (int i = level - 1; i >= 0; i--) {
      while (cur->forward[i] && cur->forward[i]->val < num)
        cur = cur->forward[i];
      update[i] = cur;
    }
    int lv = randomLevel();
    level = max(level, lv);
    Node *newnode = new Node(num, lv);
    for (int i = 0; i < lv; i++) {
      newnode->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = newnode;
    }
  }

  bool erase(int num) {
    vector<Node *> update(MAX_LEVEL, head);
    Node *cur = this->head;
    for (int i = level - 1; i >= 0; i--) {
      while (cur->forward[i] && cur->forward[i]->val < num)
        cur = cur->forward[i];
      update[i] = cur;
    }
    cur = cur->forward[0];
    if (!cur || cur->val != num)
      return false;

    for (int i = 0; i < level; i++) {
      if (update[i]->forward[i] != cur)
        break;
      update[i]->forward[i] = cur->forward[i];
    }
    delete cur;
    while (level > 1 && head->forward[level - 1] == nullptr)
      level--;

    return true;
  }

  int randomLevel() {
    int lv = 1;
    while (dis(gen) < P_FACTOR && lv < MAX_LEVEL)
      lv++;
    return lv;
  }
};
