#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int x;
  std::cin >> x;

  int w = x & -x;
  while (!(w ^ x) || !(w & x)) {
    w++;
  }
  std::cout << w << '\n';
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
