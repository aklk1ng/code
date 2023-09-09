#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    double ans = 0;
    int pre = 0;
    for (auto &bracket : brackets) {
      int upper = bracket[0], percent = bracket[1];
      int pay = (min(income, upper) - pre) * percent;
      ans += pay;
      if (income <= upper)
        break;
      pre = upper;
    }
    return (double)ans / 100.0;
  }
};
