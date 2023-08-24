#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
    vector<int> res;
    if (k == 0 || k > input.size())
      return res;
    priority_queue<int, vector<int>> pq;
    for (auto &val : input) {
      if (pq.size() < k)
        pq.push(val);
      else {
        if (val < pq.top()) {
          pq.pop();
          pq.push(val);
        }
      }
    }
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }
};

class Solution2 {
public:
  int partition(vector<int> &input, int l, int r) {
    int pivot = input[r - 1];
    int i = l;
    for (int j = l; j < r - 1; j++) {
      if (input[j] < pivot)
        swap(input[i++], input[j]);
    }
    swap(input[i], input[r - 1]);
    return i;
  }
  vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
    vector<int> res;
    if (k == 0 || k > input.size())
      return res;
    return res;
    int l = 0, r = input.size();
    while (l < r) {
      int p = partition(input, l, r);
      if (p + 1 == k)
        return vector<int>{input.begin(), input.begin() + k};
      else if (p + 1 < k)
        l = p + 1;
      else
        r = p;
    }
    return res;
  }
};
