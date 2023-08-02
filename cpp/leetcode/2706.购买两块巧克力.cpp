#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int buyChoro(vector<int> prices, int money) {
    int a = INT_MAX, b = INT_MAX;
    for (auto x : prices) {
      if (x < a)
        b = a, a = x;
      else if (x < b)
        b = x;
    }
    int ans = money - a - b;
    return ans >= 0 ? ans : money;
  }
};
