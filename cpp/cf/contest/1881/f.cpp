#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> mark(n);
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    a--;
    mark[a] = 1;
  }

  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dis(n);
  auto bfs = [&](int x) {
    queue<int> q;
    dis.assign(n, -1);
    q.push(x);
    dis[x] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      for (auto &y : adj[x]) {
        if (dis[y] == -1) {
          dis[y] = dis[x] + 1;
          q.push(y);
        }
      }
    }

    int t = -1;
    for (int i = 0; i < n; i++) {
      if (mark[i] && (t == -1 || dis[i] > dis[t])) {
        t = i;
      }
    }
    return t;
  };

  int a = bfs(0);
  int b = bfs(a);
  auto f = dis;
  bfs(b);
  for (int i = 0; i < n; i++) {
    f[i] = max(f[i], dis[i]);
  }
  int ans = *min_element(f.begin(), f.end());
  cout << ans << '\n';
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
