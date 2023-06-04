#include <bits/stdc++.h>

using namespace std;

class Soluton {
public:
  int fib(int n) {
    if (n <= 1)
      return n;
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 100000007;
    }
    return dp[n];
  }
};
