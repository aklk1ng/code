#include <bits/stdc++.h>

using namespace std;

class FrontMiddleBackQueue {
private:
  vector<int> q;

public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) { q.insert(q.begin(), val); }

  void pushMiddle(int val) {
    int pos = q.size() / 2;
    q.insert(q.begin() + pos, val);
  }

  void pushBack(int val) { q.push_back(val); }

  int popFront() {
    if (q.empty())
      return -1;

    int ret = q[0];
    q.erase(q.begin());
    return ret;
  }

  int popMiddle() {
    if (q.empty())
      return -1;

    int pos = (q.size() - 1) / 2;
    int ret = q[pos];
    q.erase(q.begin() + pos);
    return ret;
  }

  int popBack() {
    if (q.empty())
      return -1;
    int ret = q.back();
    q.pop_back();
    return ret;
  }
};
