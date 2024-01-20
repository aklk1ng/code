#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 3e5 + 9;

vector<vector<int>> g(N, vector<int>());
vector<vector<pair<int, int>>> q(N);
vector<ll> res(N), add(N);

void dfs(int v, int pr, int h, ll sum) {
  for (auto &p : q[v]) {
    int l = h, r = h + p.first;
    add[l] += p.second;
    if (r + 1 < N) {
      add[r + 1] -= p.second;
    }
  }
  sum += add[h];
  res[v] = sum;
  for (auto &e : g[v]) {
    if (e != pr) {
      dfs(e, v, h + 1, sum);
    }
  }
  for (auto &p : q[v]) {
    int l = h, r = h + p.first;
    add[l] -= p.second;
    if (r + 1 < N) {
      add[r + 1] += p.second;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v, h, d;
    cin >> v >> h >> d;
    v--;
    q[v].push_back({h, d});
  }
  dfs(0, 0, 0, 0);
  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (false) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
