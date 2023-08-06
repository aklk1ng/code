#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double averageWaiting(vector<vector<int>> &customers) {
    int start = customers[0][0], n = customers.size();
    double res = 0;
    for (auto &customer : customers) {
      start = max(start, customer[0]) + customer[1];
      res += start - customer[0];
    }
    return res;
  }
};
