#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minStartValue(vector<int> &nums) {
    int sum = 0;
    int sumMin = 0;
    for (int s : nums) {
      sum += s;
      sumMin = min(sumMin, sum);
    }
    return 1 - sumMin;
  }
};
