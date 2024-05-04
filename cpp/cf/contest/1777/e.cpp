#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector edges(n, std::vector<std::pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--, v--;
    edges[u].push_back({v, w});
  }

  auto dfs = [&](auto self, std::vector<bool> &vis, int v, int &root,
                 std::vector<std::vector<int>> &t) -> void {
    vis[v] = true;
    for (auto e : t[v]) {
      if (!vis[e]) {
        self(self, vis, e, root, t);
      }
    }
    root = v;
  };
  auto cnt = [&](auto self, int v, std::vector<bool> &vis,
                 std::vector<std::vector<int>> &t) -> int {
    int res = 1;
    vis[v] = true;
    for (auto &e : t[v]) {
      if (!vis[e]) {
        res += self(self, e, vis, t);
      }
    }
    return res;
  };
  int l = -1, r = 1e9 + 1;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    std::vector<std::vector<int>> v(n);
    for (int i = 0; i < n; i++) {
      for (auto &e : edges[i]) {
        v[i].push_back(e.first);
        if (e.second <= mid) {
          v[e.first].push_back(i);
        }
      }
    }
    std::vector<bool> vis(n);
    int root = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        dfs(dfs, vis, i, root, v);
      }
    }
    vis.assign(n, false);
    if (cnt(cnt, root, vis, v) == n) {
      r = mid;
    } else {
      l = mid;
    }
  }

  std::cout << (r == 1e9 + 1 ? -1 : r) << '\n';
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
