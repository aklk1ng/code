// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1e3 + 5;

struct Edge {
  ll v, w;
  bool operator<(const Edge &y) const { return w == y.w ? v < y.v : w > y.w; }
};
vector<Edge> g[N];
ll d[N][N];
int n, m, q;

void solve() {
  cin >> n >> m >> q;
  memset(d, 0x3f, sizeof d);
  for (int i = 1; i <= m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    d[u][v] = min(d[u][v], w);
  }
  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  while (q--) {
    ll u, v;
    cin >> u >> v;
    cout << (d[u][v] >= 0x3f3f3f3f3f3f3f3f ? -1 : d[u][v]) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }
  solve();

  return 0;
}
