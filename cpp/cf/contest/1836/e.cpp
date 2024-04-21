#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int k, n;
  std::cin >> k;
  n = 2 << k;
  std::vector<ll> g(n + 1);
  std::vector<int> hbits(1 << k, -1);
  std::vector<std::pair<int, int>> lbits(1 << k, {-1, -1});
  auto add = [&lbits, &g](int s, int e) {
    int rem = g[e] ^ g[s - 1];
    auto &[os, oe] = lbits[rem];

    if (os == -1) {
      os = s, oe = e;
      return false;
    }
    if (oe < s) {
      std::cout << os << ' ' << oe << ' ' << s << ' ' << e << '\n';
    } else {
      std::cout << std::min(s, os) << ' ' << std::max(s, os) - 1 << ' '
                << oe + 1 << ' ' << e << '\n';
    }
    return true;
  };
  hbits[0] = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> g[i];
    g[i] ^= g[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    if (hbits[g[i] >> k] != -1) {
      if (add(hbits[g[i] >> k] + 1, i)) {
        break;
      }
    }
    hbits[g[i] >> k] = i;
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
