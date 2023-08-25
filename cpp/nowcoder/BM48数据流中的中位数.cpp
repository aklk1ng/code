#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  priority_queue<int> min_q;
  priority_queue<int, vector<int>, greater<int>> max_q;
  void Insert(int num) {
    min_q.push(num);
    max_q.push(min_q.top());
    min_q.pop();

    if (min_q.size() < max_q.size()) {
      min_q.push(max_q.top());
      max_q.pop();
    }
  }
  double GetMedian() {
    if (min_q.size() > max_q.size())
      return (double)min_q.top();
    else
      return (double)(min_q.top() + max_q.top()) / 2;
  }
};
