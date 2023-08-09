#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int sum = 0, ans = 0;
    for (auto &num : gain) {
      sum += num;
      ans = max(ans, sum);
    }
    return ans;
  }
};
