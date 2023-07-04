#include <bits/stdc++.h>

using namespace std;

class StackOfPlates {
public:
  StackOfPlates(int cap) { capacity = cap; }

  void push(int val) {
    if (capacity == 0)
      return;
    if (sts.empty() || sts.back().size())
      sts.emplace_back(stack<int>());

    sts.back().push(val);
  }

  int pop() {
    if (capacity == 0 || sts.empty())
      return -1;

    int res = sts.back().top();
    sts.back().pop();
    if (sts.back().empty())
      sts.pop_back();

    return res;
  }

  int popAt(int index) {
    if (capacity == 0 || index >= sts.size() || sts[index].empty())
      return -1;

    int res = sts[index].top();
    sts.back().pop();

    if (sts[index].empty())
      sts.pop_back();

    return res;
  }

private:
  vector<stack<int>> sts;
  int capacity;
};
