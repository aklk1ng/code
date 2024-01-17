#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  vector edges(N, vector<int>()), dist(2, vector<int>(N));
  vector<int> q(N);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  auto bfs = [&](vector<int> &t, int s) {
    fill(t.begin(), t.end(), INF);
    int hh = 0, tt = 0;
    q[hh++] = s;
    t[s] = 0;
    while (tt < hh) {
      int x = q[tt++];
      for (auto &y : edges[x]) {
        if (t[y] == INF) {
          t[y] = t[x] + 1;
          q[hh++] = y;
        }
      }
    }
  };
  bfs(dist[0], 0);
  bfs(dist[1], n - 1);
  vector<pair<int, int>> data;
  for (int i = 0; i < k; i++) {
    data.emplace_back(dist[0][a[i]] - dist[1][a[i]], a[i]);
  }
  sort(data.begin(), data.end());
  int best = 0;
  int mx = -INF;
  for (auto &e : data) {
    int t = e.second;
    best = max(best, mx + dist[1][t]);
    mx = max(mx, dist[0][t]);
  }
  cout << min(dist[0][n - 1], best + 1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  if (false) {
    cin >> tt;
  }
  while (tt--) {
    solve();
  }

  return 0;
}
