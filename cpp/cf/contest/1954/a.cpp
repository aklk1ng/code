#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  int mx = (n + m - 1) / m;
  if (mx + k >= n) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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
