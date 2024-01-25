#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

int n, m;
std::vector<ll> a(N), dist(N);
std::vector<std::pair<int, ll>> g[N];

void dijkstra() {
  std::set<std::pair<ll, int>> q;
  for (int i = 0; i < n; i++) {
    dist[i] = a[i];
    q.insert({dist[i], i});
  }

  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());

    for (auto &[u, w] : g[v]) {
      if (dist[u] > dist[v] + w) {
        q.erase({dist[u], u});
        dist[u] = dist[v] + w;
        q.insert({dist[u], u});
      }
    }
  }
}

void solve() {
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int f, t;
    ll w;
    std::cin >> f >> t >> w;
    f--, t--;
    w *= 2;
    g[f].push_back({t, w});
    g[t].push_back({f, w});
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  dijkstra();
  for (int i = 0; i < n; i++) {
    std::cout << dist[i] << " \n"[i == n - 1];
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
