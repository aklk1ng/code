#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1);
    // 偷第一家
    dp[1] = nums[0];
    for (int i = 2; i < n; i++)
      dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    int res = dp[n - 1];

    // 不偷第一家
    dp.clear();
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
      dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    return max(res, dp[n]);
  }
};
