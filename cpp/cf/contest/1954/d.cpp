#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  auto add = [&](int x, int y) {
    x += y;
    if (x >= mod) {
      x -= mod;
    }
    return x;
  };
  auto mul = [&](int x, int y) { return x * 1LL * y % mod; };
  int s = std::accumulate(a.begin(), a.end(), 0);
  std::vector<int> dp(s + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = s - a[i]; j >= 0; j--) {
      dp[j + a[i]] = add(dp[j + a[i]], dp[j]);
    }
  }
  int ans = 0;
  for (int j = 0; j <= s; j++) {
    ans = add(ans, mul((j + 1) / 2, dp[j]));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      ans = add(ans, mul(a[i] - (a[i] + j + 1) / 2, dp[j]));
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
