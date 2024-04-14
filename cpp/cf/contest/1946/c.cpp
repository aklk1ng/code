#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector adj(n, std::vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto check = [&](int x) {
    int res = 0;
    auto dfs = [&](auto self, int v, int p) -> int {
      int sz = 1;
      for (auto &u : adj[v]) {
        if (u == p) {
          continue;
        }
        sz += self(self, u, v);
      }
      if (sz >= x && p != v) {
        res++, sz = 0;
      }
      return sz;
    };

    int t = dfs(dfs, 0, 0);
    return (res > k || (t >=x && res == k) ? true : false);
  };

  int l = 1, r = n / (k + 1) + 1;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  std::cout << l << '\n';
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
