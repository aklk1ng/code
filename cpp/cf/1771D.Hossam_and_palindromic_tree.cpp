#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::vector g(n, std::vector<int>()), go(n, std::vector<int>(n)),
      dp(n, std::vector<int>(n));
  std::vector k(n, std::vector<std::pair<int, int>>());

  auto dfs = [&](auto self, int v, int a, int t = -1, int p = -1,
                 int len = 0) -> void {
    if (len == 1) {
      t = v;
    }
    if (len > 1) {
      go[a][v] = t;
    }
    k[len].push_back({a, v});

    for (auto &u : g[v]) {
      if (u != p) {
        self(self, u, a, t, v, len + 1);
      }
    }
  };
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int v = 0; v < n; v++) {
    dfs(dfs, v, v);
  }

  for (int i = 0; i < n; i++) {
    for (auto &[v, u] : k[i]) {
      if (!i) {
        dp[v][u] = 1;
      } else if (i == 1) {
        dp[v][u] = 1 + (s[v] == s[u]);
      } else {
        int x = dp[v][go[u][v]];
        int y = dp[go[v][u]][u];
        int z = dp[go[v][u]][go[u][v]] + ((s[v] == s[u]) << 1);
        dp[v][u] = std::max({x, y, z});
      }
    }
  }

  int ans = 0;
  for (int v = 0; v < n; v++) {
    for (int u = 0; u < n; u++) {
      ans = std::max(ans, dp[v][u]);
    }
  }
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
