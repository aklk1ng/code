#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(5, -10000));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return max(dp[n - 1][2], max(0, dp[n - 1][4]));
  }
};

class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < n; i++) {
      buy1 = max(buy1, -prices[i]);
      sell1 = max(sell1, buy1 + prices[i]);
      buy2 = max(buy2, sell1 - prices[i]);
      sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
  }
};
