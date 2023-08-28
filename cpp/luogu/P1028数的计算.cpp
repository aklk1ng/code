// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 1e3 + 10;
ll dp[N];

void solve() {
  int n;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      dp[i] += dp[j];
    }
    dp[i]++;
  }
  std::cout << dp[n] << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
