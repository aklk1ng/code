#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> g(n);
  for (int i = 0; i < n; i++) {
    std::cin >> g[i];
  }

  auto ans = "YES\n";
  if (g[0][0] != g[n - 1][m - 1]) {
    bool ok = false;
    for (int j = 0; j < m - 1; j++) {
      if (g[0][j] != g[0][j + 1] || g[n - 1][j] != g[n - 1][j + 1]) {
        ok = true;
      }
    }
    if (!ok) {
      ans = "NO\n";
    }
    ok = false;
    for (int i = 0; i < n - 1; i++) {
      if (g[i][0] != g[i + 1][0] || g[i][m - 1] != g[i + 1][m - 1]) {
        ok = true;
      }
    }
    if (!ok) {
      ans = "NO\n";
    }
  }
  std::cout << ans;
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
