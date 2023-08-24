#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> maxInWindows(vector<int> &num, int size) {
    vector<int> res;
    int n = num.size();
    if (n == 0 || n < size || size == 0)
      return res;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      while (!dq.empty() && num[dq.back()] < num[i])
        dq.pop_back();
      dq.push_back(i);
      if (dq.front() + size >= i)
        dq.pop_front();
      if (i + 1 >= size)
        res.push_back(num[dq.front()]);
    }
    return res;
  }
};
