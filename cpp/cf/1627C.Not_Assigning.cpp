#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::array<int, 2>>> g(n);
  std::vector<int> deg(n), a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
    deg[u]++;
    deg[v]++;
  }
  if (*std::max_element(deg.begin(), deg.end()) > 2) {
    std::cout << "-1\n";
    return;
  }
  auto dfs = [&](auto self, int v, int p, int c) -> void {
    for (auto &[u, i] : g[v]) {
      if (u != p) {
        a[i] = c;
        self(self, u, v, c ^ 1);
      }
    }
  };
  dfs(dfs, std::min_element(deg.begin(), deg.end()) - deg.begin(), -1, 0);
  for (auto &e : a) {
    std::cout << e + 2 << ' ';
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
