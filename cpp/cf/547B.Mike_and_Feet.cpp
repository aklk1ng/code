#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 1e6 + 5;
vector<int> par(N), sz(N, 1), ans(N);
vector<bool> mark(N);

int find(int v) { return (par[v] == v ? v : par[v] = find(par[v])); }

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  par[u] = v;
  sz[v] += sz[u];
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < N; i++) {
    par[i] = i;
  }
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p.begin(), p.end(), greater<pair<int, int>>());
  int cur = 1;
  for (int i = 0; i < n; i++) {
    int pos = p[i].second;
    int val = p[i].first;
    mark[pos] = true;
    if (pos && mark[pos - 1]) {
      merge(pos, pos - 1);
    }
    if (pos < n - 1 && mark[pos + 1]) {
      merge(pos, pos + 1);
    }
    int t = sz[find(pos)];
    while (cur <= t) {
      ans[cur++] = val;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
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
