#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> dp(n + 5);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    dp[i] = std::min(dp[i - 1] + 1, x);
    ans += dp[i];
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
