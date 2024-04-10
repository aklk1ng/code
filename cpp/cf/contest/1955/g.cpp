#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  int ans = 1, g = std::__gcd(a[0][0], a[n - 1][m - 1]);
  std::vector dp(n, std::vector<char>(m));
  for (int x = 1; x * x <= g; x++) {
    if (g % x > 0) {
      continue;
    }
    std::vector<int> cand{x, g / x};
    for (auto &e : cand) {
      for (int i = 0; i < n; i++) {
        dp[i].assign(m, 0);
      }
      dp[0][0] = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] % e > 0) {
            continue;
          }
          if (!dp[i][j] && i) {
            dp[i][j] = (dp[i - 1][j] == 1 ? 1 : 0);
          }
          if (!dp[i][j] && j) {
            dp[i][j] = (dp[i][j - 1] == 1 ? 1 : 0);
          }
        }
      }
      if (dp[n - 1][m - 1]) {
        ans = std::max(ans, e);
      }
    }
  }
  std::cout << ans << '\n';
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
