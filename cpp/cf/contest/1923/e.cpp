#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }
  std::vector g(n, std::vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> v >> u;
    u--, v--;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  ll ans = 0;
  std::vector<std::map<int, int>> cnt(n);
  auto dfs = [&](auto self, int v, int p = -1) -> void {
    int bst = -1;
    for (int &u : g[v]) {
      if (u != p) {
        self(self, u, v);
      }
      if (bst == -1 || cnt[bst].size() < cnt[u].size()) {
        bst = u;
      }
    }
    for (int &u : g[v]) {
      if (u != p && u != bst) {
        for (auto &[x, y] : cnt[u]) {
          if (x != c[v]) {
            ans += cnt[bst][x] * 1LL * y;
          }
          cnt[bst][x] += y;
        }
      }
    }
    if (bst != -1) {
      std::swap(cnt[bst], cnt[v]);
    }
    ans += cnt[v][c[v]];
    cnt[v][c[v]] = 1;
  };
  dfs(dfs, 0);
  std::cout << ans << '\n';
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
