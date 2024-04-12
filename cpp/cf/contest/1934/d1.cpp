#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  ll n, m;
  std::cin >> n >> m;

  ll hi = 0, sec = 0;
  for (ll p = (1LL << 62); p > 0; p >>= 1) {
    if (p & n) {
      if (!hi) {
        hi = p;
      } else if (!sec) {
        sec = p;
      }
    }
  }
  bool ok = (sec && ((m & hi) || (m < sec * 2)));
  if (!ok) {
    std::cout << "-1\n";
    return;
  }
  std::vector<ll> ans{n, m};
  if (!(m & hi) && !(m & sec)) {
    ans = {n, m ^ sec, m};
  }
  std::cout << ans.size() - 1 << '\n';
  for (auto &e : ans) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
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
