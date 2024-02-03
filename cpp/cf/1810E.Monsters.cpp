#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), vis(n + 1);
  std::vector adj(n + 1, std::vector<int>());
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto check = [&](int u) {
    std::set<std::pair<int, int>> s;
    s.insert({a[u], u});
    int cur = 0, d = 0;
    while (!s.empty()) {
      auto it = *s.begin();
      vis[it.second] = u;
      if (it.first > d) {
        return cur == n;
      }
      s.erase(s.begin());
      cur++, d++;
      for (auto &v : adj[it.second]) {
        if (vis[v] < u) {
          s.insert({a[v], v});
        }
      }
    }
    return cur == n;
  };
  for (int i = 1; i <= n; i++) {
    if (!a[i] && !vis[i]) {
      if (check(i)) {
        std::cout << "YES\n";
        return;
      }
    }
  }
  std::cout << "NO\n";
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
