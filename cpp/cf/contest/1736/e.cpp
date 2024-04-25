#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector dp(n + 2, std::vector(n + 2, std::vector<int>(n + 2, INT_MIN)));
  std::vector pref(n + 2, std::vector<int>(n + 2));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= i; k++) {
        if (k) {
          dp[i][j][k] = dp[i - 1][j][k - 1] + a[j];
        }
        if (j >= i) {
          int need = j - i;
          if (need > k) {
            continue;
          }
          dp[i][j][k] = std::max(dp[i][j][k], pref[k - need][j - 1] + a[j]);
        }
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= i; k++) {
        pref[k][j] = std::max(pref[k][j], dp[i][j][k]);
      }
    }
    for (int j = 0; j <= i; j++) {
      for (int k = 1; k <= n; k++) {
        pref[j][k] = std::max(pref[j][k], pref[j][k - 1]);
        ans = std::max(ans, pref[j][k]);
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
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
