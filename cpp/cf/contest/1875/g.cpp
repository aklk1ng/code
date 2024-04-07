#include <bits/stdc++.h>
typedef long long ll;
const long double INF = 1e18;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector dp(n + 1, std::vector<long double>(m + 1, INF));
  dp[0][0] = 0.00;
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= m; x++) {
      for (int y = 1; x + y * (n - i + 1) <= m; y++) {
        dp[i][x + y] = std::min(dp[i][x + y], dp[i - 1][x] + 1.00 * x / y);
      }
    }
  }
  std::cout << std::fixed << std::setprecision(12) << 2 * dp[n][m] + n << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
