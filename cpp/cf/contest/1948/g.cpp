#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector g(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> g[i][j];
      if (!g[i][j]) {
        g[i][j] = INT_MAX;
      }
    }
  }

  auto cal = [&](int mask) {
    std::vector<int> d(n, INT_MAX);
    std::vector<bool> vis(n);
    d[0] = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int id = -1;
      for (int j = 0; j < n; j++) {
        if (!vis[j] && d[j] < INT_MAX && (id == -1 || d[j] < d[id])) {
          id = j;
        }
      }
      if (id == -1) {
        return INT_MAX;
      }
      vis[id] = true;
      res += d[id];
      for (int k = 0; k < n; k++) {
        if (vis[k]) {
          continue;
        }
        if ((mask & (1 << id)) == 0 && (mask & (1 << k)) == 0) {
          continue;
        }
        d[k] = std::min(d[k], g[id][k]);
      }
    }
    return res;
  };
  int ans = INT_MAX;
  for (int i = 0; i < (1 << n); i++) {
    int cur = cal(i);
    if (cur != INT_MAX) {
      ans = std::min(ans, cur + c * __builtin_popcount(i));
    }
  }
  std::cout << ans << '\n';
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
