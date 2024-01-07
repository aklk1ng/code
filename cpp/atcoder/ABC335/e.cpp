#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) : data(sz, -1) {}
  bool unionSet(int x, int y) {
    x = root(x), y = root(y);
    if (x != y) {
      if (data[x] < data[y]) {
        swap(x, y);
      }
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  UnionFind uf(n);
  vector vp(N, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (a[u] > a[v]) {
      swap(u, v);
    }
    if (a[u] == a[v]) {
      uf.unionSet(u, v);
    } else {
      vp[a[u]].push_back({u, v});
    }
  }

  vector<int> dp(N, -INF);
  dp[uf.root(0)] = 1;
  for (auto &e : vp) {
    for (auto &[u, v] : e) {
      u = uf.root(u);
      v = uf.root(v);
      if (dp[u] > 0) {
        dp[v] = max(dp[v], dp[u] + 1);
      }
    }
  }
  cout << max(0, dp[uf.root(n - 1)]) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
