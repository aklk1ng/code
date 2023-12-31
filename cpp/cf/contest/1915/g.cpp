#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int64_t INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n];
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<vector<int64_t>> dist(n, vector<int64_t>(1001, INF));
  vector<vector<bool>> vis(n, vector<bool>(1001, false));
  dist[0][s[0]] = 0;
  priority_queue<array<int64_t, 3>> q;
  q.push({0, 0, s[0]});
  while (!q.empty()) {
    int u = q.top()[1], k = q.top()[2];
    q.pop();
    if (vis[u][k] || dist[u][k] == INF) {
      continue;
    }
    vis[u][k] = true;
    for (auto &e : adj[u]) {
      auto [v, w] = e;
      int c = min(s[v], k);
      if (dist[v][c] > dist[u][k] + 1LL * w * k) {
        dist[v][c] = dist[u][k] + 1LL * w * k;
        q.push({-dist[v][c], v, c});
      }
    }
  }
  int64_t ans = INF;
  for (int i = 1; i <= 1000; i++) {
    ans = min(ans, dist[n - 1][i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
