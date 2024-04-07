#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k, d;
  std::cin >> n >> m >> k >> d;
  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::vector<ll> dp(m, 1e9), v(m);
    std::multiset<ll> ms = {1};
    dp[0] = 1;
    std::cin >> v[0];
    for (int j = 1; j < m - 1; j++) {
      std::cin >> v[j];
      dp[j] = *ms.begin() + v[j] + 1;
      if (j - d - 1 >= 0) {
        ms.erase(ms.find((dp[j - d - 1])));
      }
      ms.insert(dp[j]);
    }
    std::cin >> v.back();
    dp.back() = 1 + *ms.begin();
    a[i] = dp.back();
  }

  ll cur = 0;
  for (int i = 0; i < k; i++) {
    cur += a[i];
  }
  ll mi = cur;
  for (int i = k; i < n; i++) {
    cur += a[i] - a[i - k];
    mi = std::min(mi, cur);
  }
  std::cout << mi << '\n';
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
