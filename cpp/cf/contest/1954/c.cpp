#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string x, y;
  std::cin >> x >> y;

  int n = x.size();
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if ((x[i] > y[i]) == ok) {
      std::swap(x[i], y[i]);
    }
    ok |= x[i] != y[i];
  }
  std::cout << x << '\n' << y << '\n';
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
