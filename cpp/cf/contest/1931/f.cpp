#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector a(k, std::vector<int>(n));
  std::vector<int> p(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
      a[i][j]--;
    }
    p[i] = a[i][0];
  }

  std::vector g(n, std::vector<int>());
  for (int i = 0; i < k; i++) {
    for (int j = 1; j < n - 1; j++) {
      g[a[i][j]].push_back(a[i][j + 1]);
    }
  }
  std::vector<int> tot(n, -1);
  std::vector<bool> vis(n);
  int t = 0;
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int &v : g[u]) {
      if (!vis[v]) {
        self(self, v);
      }
    }
    tot[u] = t++;
  };
  for (int i = 0; i < n; i++) {
    if (tot[i] == -1) {
      dfs(dfs, i);
    }
  }

  for (int i = 0; i < k; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (tot[a[i][j]] < tot[a[i][j + 1]]) {
        std::cout << "NO\n";
        return;
      }
    }
  }
  std::cout << "YES\n";
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
