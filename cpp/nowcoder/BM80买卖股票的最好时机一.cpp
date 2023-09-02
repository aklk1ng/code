#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[i][0] 表示到第i天为止不持股的最大收益
    dp[0][0] = 0;
    // dp[i][1] 表示到第i天为止持股的最大收益
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[n - 1][0];
  }
};

class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int min_price = INT_MAX;
    int res = INT_MIN;
    for (int price : prices) {
      min_price = min(min_price, price);
      res = max(res, price - min_price);
    }
    return res;
  }
};
