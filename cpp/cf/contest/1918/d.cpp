#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll l = 0, r = 1LL * 1e9 * n;
  while (l < r) {
    ll mid = (l + r) / 2;
    std::set<std::pair<ll, int>> pos;
    std::vector<ll> dp(n + 1);
    int p = n;
    pos.insert({dp[n], n});
    ll sum = 0;
    for (int j = n - 1; j >= 0; j--) {
      while (sum > mid) {
        sum -= a[p - 1];
        pos.erase({dp[p], p});
        p--;
      }
      dp[j] = pos.begin()->first + a[j];
      pos.insert({dp[j], j});
      sum += a[j];
    }
    sum = 0;
    bool ok = false;
    for (int j = 0; j < n; j++) {
      if (sum <= mid && dp[j] <= mid) {
        ok = true;
      }
      sum += a[j];
    }
    if (ok) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  std::cout << l << '\n';
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
