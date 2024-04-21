#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  ll n, k, g;
  std::cin >> n >> k >> g;

  ll len = std::min((g - 1) / 2 * n, k * g);
  ll rest = (k * g - len) % g;
  if (rest > 0) {
    len -= (g - 1) / 2;
    ll lst = ((g - 1) / 2 + rest) % g;
    if (lst * 2 < g) {
      len += lst;
    } else {
      len -= g - lst;
    }
  }
  std::cout << len << '\n';
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
