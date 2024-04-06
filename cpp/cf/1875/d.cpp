#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<ll> dp(5e3 + 5, 2e18);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x < n) {
      a[x]++;
    }
  }
  int m = 0;
  while (a[m]) {
    m++;
  }
  dp[m] = 0;
  for (int i = m; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      dp[j] = std::min(dp[j], dp[i] + i * a[j]);
    }
  }
  std::cout << dp[0] - m << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
