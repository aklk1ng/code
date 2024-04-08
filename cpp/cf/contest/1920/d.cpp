#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<ll> dp(n + 1);
  std::vector<int> lst(n + 1);
  for (int i = 1; i <= n; i++) {
    int a, v;
    std::cin >> a >> v;
    if (a == 1) {
      lst[i] = v;
      dp[i] = dp[i - 1] + 1;
    } else {
      lst[i] = lst[i - 1];
      dp[i] = ((v + 1) > 2e18 / dp[i - 1]) ? (ll)2e18 : dp[i - 1] * (v + 1);
    }
  }

  while (q--) {
    ll k;
    std::cin >> k;

    while (true) {
      int pos = std::lower_bound(dp.begin(), dp.end(), k) - dp.begin();
      if (dp[pos] == k) {
        std::cout << lst[pos] << " \n"[q == 0];
        break;
      }
      if (k % dp[pos - 1] == 0) {
        std::cout << lst[pos - 1] << " \n"[q == 0];
        break;
      }
      k %= dp[pos - 1];
    }
  }
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
