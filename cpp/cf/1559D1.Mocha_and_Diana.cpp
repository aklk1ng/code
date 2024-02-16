#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;
  std::vector f(2, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    f[0][i] = f[1][i] = i;
  }

  auto get = [&](auto self, int id, int x) -> int {
    return x == f[id][x] ? x : f[id][x] = self(self, id, f[id][x]);
  };
  for (int i = 1; i <= m1; i++) {
    int u, v;
    std::cin >> u >> v;
    int fu = get(get, 0, u), fv = get(get, 0, v);
    f[0][fu] = fv;
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    std::cin >> u >> v;
    int fu = get(get, 1, u), fv = get(get, 1, v);
    f[1][fu] = fv;
  }

  std::vector<std::pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (get(get, 0, i) != get(get, 0, j) &&
          get(get, 1, i) != get(get, 1, j)) {
        ans.push_back({i, j});
        f[0][get(get, 0, i)] = get(get, 0, j);
        f[1][get(get, 1, i)] = get(get, 1, j);
      }
    }
  }

  std::cout << ans.size() << '\n';
  for (auto &[k, v] : ans) {
    std::cout << k << ' ' << v << '\n';
  }
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
