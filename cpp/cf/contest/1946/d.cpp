#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  ll n, x;
  std::cin >> n >> x;
  x++;
  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int ans = -1;
  for (int i = 30; i >= 0; i--) {
    std::vector<ll> b;
    bool ok = false;
    for (int j = 0; j < (int)a.size(); j++) {
      if (!ok) {
        b.push_back(a[j]);
      } else {
        b.back() ^= a[j];
      }
      if (a[j] & (1 << i)) {
        ok = !ok;
      }
    }

    if (!(x & (1 << i))) {
      if (ok) {
        std::cout << ans << '\n';
        return;
      }
      a = b;
    } else {
      if (!ok) {
        ans = std::max(ans, (int)b.size());
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
