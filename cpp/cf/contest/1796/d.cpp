#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k, x;
  std::cin >> n >> k >> x;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector dp(n + 1, std::vector(k + 1, std::vector<ll>(3, LONG_MIN)));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int t = 0; t < 3; t++) {
        if (dp[i][j][t] == LONG_MIN) {
          continue;
        }
        for (int jj = j; jj <= std::min(k, j + 1); jj++) {
          ll add = a[i] + (j == jj ? -x : x);
          for (int tt = t; tt < 3; tt++) {
            dp[i + 1][jj][tt] =
                std::max(dp[i + 1][jj][tt], dp[i][j][t] + (tt == 1 ? add : 0));
          }
        }
      }
    }
  }
  std::cout << std::max(dp[n][k][1], dp[n][k][2]) << '\n';
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
