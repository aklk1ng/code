#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 2e5 + 5;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  vector<vector<int>> g(n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    deg[i] = g[i].size();
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }
  vector<bool> vis(n, false);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    vis[v] = true;
    for (int &x : g[v]) {
      deg[x]--;
      if (deg[x] == 1) {
        q.push(x);
      }
    }
  }
  vector<int> p(n, -1);
  vector<int> d(n, -1);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      d[i] = 0;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int &x : g[v]) {
      if (d[x] == -1) {
        d[x] = d[v] + 1;
        p[x] = v;
        q.push(x);
      }
    }
  }
  int D = d[b];
  while (vis[b]) {
    b = p[b];
  }
  vector<int> d2(n, -1);
  d2[b] = 0;
  q.push(b);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int &x : g[v]) {
      if (d2[x] == -1) {
        d2[x] = d2[v] + 1;
        q.push(x);
      }
    }
  }
  if (d2[a] <= D) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
