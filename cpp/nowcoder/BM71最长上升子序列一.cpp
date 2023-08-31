#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int LTS(vector<int> &arr) {
    int n = arr.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    vector<int> dp(n, 1);
    int res = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          res = max(res, dp[i]);
        }
      }
    }
    return res;
  }
};
