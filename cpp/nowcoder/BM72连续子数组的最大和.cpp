#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int FindGreatestSumOfSubArray(vector<int> &array) {
    int n = array.size();
    vector<int> dp(n, 0);
    dp[0] = array[0];
    int res = dp[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(dp[i - 1] + array[i], array[i]);
      res = max(res, dp[i]);
    }
    return res;
  }
};
