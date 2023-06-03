#include <bits/stdc++.h>

using namespace std;

class Soluton1 {
public:
  int minConstClimbingStairs(vector<int> &cost) {
    vector<int> dp(cost.size() + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= cost.size(); i++) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
  }
};

class Soluton2 {
public:
  int minConstClimbingStairs(vector<int> &cost) {
    int dp0 = 0;
    int dp1 = 1;
    for (int i = 2; i <= cost.size(); i++) {
      int dpi = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
      dp0 = dp1;
      dp1 = dpi;
    }
    return dp1;
  }
};
