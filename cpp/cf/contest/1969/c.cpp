#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector dp(n + 1, std::vector<ll>(k + 1, 1e18));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      ll mi = 1e18;
      for (int d = 0; j + d <= k && i + d < n; d++) {
        mi = std::min(mi, (ll)a[i + d]);
        dp[i + d + 1][j + d] = std::min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * mi);
      }
    }
  }
  std::cout << *std::min_element(dp[n].begin(), dp[n].end()) << '\n';
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
