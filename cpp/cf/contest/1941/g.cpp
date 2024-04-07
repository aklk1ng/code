#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector g(n + 1, std::vector<std::pair<int, int>>());
  std::map<int, int> mp;
  int id = n + 1;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
    if (!mp.count(c)) {
      mp[c] = id++;
    }
  }

  int b, e;
  std::cin >> b >> e;
  if (b == e) {
    std::cout << "0\n";
    return;
  }

  std::vector<std::set<int>> vi(n + mp.size() + 3);
  for (int i = 1; i <= n; i++) {
    for (auto &[to, c] : g[i]) {
      int tmp = mp[c];
      vi[i].insert(tmp);
      vi[tmp].insert(i);

      vi[to].insert(tmp);
      vi[tmp].insert(to);
    }
  }

  std::vector<int> vis(vi.size()), d(vi.size(), -1);
  auto bfs = [&](int v) {
    std::queue<int> q;
    q.push(v);
    vis[v] = 1;
    d[v] = 0;
    while (!q.empty()) {
      auto from = q.front();
      q.pop();
      for (auto &to : vi[from]) {
        if (!vis[to]) {
          q.push(to);
          vis[to] = 1;
          d[to] = d[from] + 1;
        }
      }
    }
  };
  bfs(b);
  std::cout << (d[e] > 0 ? d[e] / 2 : -1) << '\n';
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
