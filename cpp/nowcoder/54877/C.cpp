// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

const ll M = 1e18;
ll dp[1000];

void solve() {
  ll p, q;
  std::cin >> p >> q;
  dp[1] = p;
  dp[2] = q;
  int n;
  for (n = 3;; n++) {
    dp[n] = std::pow(dp[n - 2], dp[n - 1]);
    if (dp[n] < 0 || dp[n] > M)
      break;
  }
  std::cout << n - 1 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
