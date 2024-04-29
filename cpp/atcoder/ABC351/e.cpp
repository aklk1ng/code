#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  ll ans = 0;
  std::vector<std::vector<ll>> a(4);
  for (int i = 0; i < n; i++) {
    ll x, y;
    std::cin >> x >> y;
    if ((x + y) % 2 == 0) {
      a[0].push_back(x + y);
      a[1].push_back(x - y);
    } else {
      a[2].push_back(x + y);
      a[3].push_back(x - y);
    }
  }

  for (int i = 0; i < 4; i++) {
    std::sort(a[i].begin(), a[i].end());
    int sz = a[i].size();
    for (int j = 0; j < sz; j++) {
      ans += a[i][j] * (2 * j + 1 - sz);
    }
  }
  std::cout << ans / 2 << '\n';
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
