#include <bits/stdc++.h>

using namespace std;

class Soluton1 {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    else
      return fib(n - 1) + fib(n - 2);
  }
};

class Soluton2 {
public:
  int fib(int n) {
    if (n == 1)
      return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

class Soluton3 {
public:
  int fib(int n) {
    if (n == 1)
      return n;
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      int sum = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = sum;
    }
    return dp[1];
  }
};
