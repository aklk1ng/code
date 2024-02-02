#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector d(n, std::vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    d[u][v] = w;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] == INF || d[k][j] == INF) {
          continue;
        }
        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  std::vector dp(1 << n, std::vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 0;
  }
  for (int k = 1; k < (1 << n) - 1; k++) {
    for (int i = 0; i < n; i++) {
      if (~k >> i & 1) {
        continue;
      }
      if (dp[k][i] == INF) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        if (k >> j & 1) {
          continue;
        }
        if (d[i][j] == INF) {
          continue;
        }
        dp[k | 1 << j][j] = std::min(dp[k | 1 << j][j], dp[k][i] + d[i][j]);
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < n; i++) {
    ans = std::min(ans, dp[(1 << n) - 1][i]);
  }
  if (ans == INF) {
    std::cout << "No\n";
  } else {
    std::cout << ans << '\n';
  }
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
