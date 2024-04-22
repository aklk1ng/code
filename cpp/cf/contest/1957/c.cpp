#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

std::vector<int> dp(3e5 + 5);

void solve() {
  int n, k;
  std::cin >> n >> k;
  int vis = 0;
  for (int i = 0; i < k; i++) {
    int r, c;
    std::cin >> r >> c;
    vis += 2 - (r == c);
  }

  int m = n - vis;
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= m; i++) {
    dp[i] = (dp[i - 1] + 2LL * (i - 1) * dp[i - 2] % mod) % mod;
  }
  std::cout << dp[m] << '\n';
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
