#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int l, r;
  std::cin >> l >> r;

  int mx = 1;
  while ((l << mx) <= r) {
    mx++;
  }
  int ans = (r / (1 << (mx - 1)) - l + 1);
  if (mx > 1) {
    ans += (mx - 1) * std::max(0, (r / (1 << (mx - 2)) / 3 - l + 1));
  }
  std::cout << mx << ' ' << ans << '\n';
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
