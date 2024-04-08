#include <bits/stdc++.h>
typedef long long ll;

const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector dp(n + 1, std::vector<int>(k + 1));
  std::fill(dp[0].begin(), dp[0].end(), 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int p = 1; j * p <= i && j + p - 1 <= k; p++) {
        dp[i][j] = (dp[i][j] + dp[i - j * p][p]) % mod;
      }
      if (i == n) {
        ans = (ans + dp[i][j]) % mod;
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
