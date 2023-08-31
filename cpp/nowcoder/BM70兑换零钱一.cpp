#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minMoney(vector<int> &arr, int aim) {
    if (aim < 1)
      return 0;
    vector<int> dp(aim + 1, aim + 1);
    dp[0] = 0;
    for (int i = 1; i <= aim; i++) {
      for (int val : arr) {
        if (val <= i)
          dp[i] = min(dp[i], dp[i - val] + 1);
      }
    }
    return dp[aim] > aim ? -1 : dp[aim];
  }
};
