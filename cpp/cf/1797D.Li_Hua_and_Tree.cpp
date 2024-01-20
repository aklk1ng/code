#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

vector<vector<ll>> e(N);
vector<ll> a(N), son(N), sz(N), fa(N), sum(N);
vector<set<tuple<ll, ll>>> sons(N);

void dfs(ll u, ll f) {
  sz[u] = 1;
  sum[u] = a[u];
  fa[u] = f;
  for (auto &v : e[u]) {
    if (v == f) {
      continue;
    }
    dfs(v, u);
    sz[u] += sz[v];
    sum[u] += sum[v];
    sons[u].insert({-sz[v], v});
    if ((sz[v] > sz[son[u]]) || (sz[v] == sz[son[u]] && v < son[u])) {
      son[u] = v;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  while (m--) {
    int op, u;
    cin >> op >> u;
    if (op == 1) {
      cout << sum[u] << '\n';
    } else {
      ll v = son[u];
      if (!v) {
        continue;
      }
      ll p = fa[u];
      sz[u] -= sz[v];
      sum[u] -= sum[v];
      sons[u].erase({-sz[v], v});
      son[u] = sons[u].empty() ? 0 : get<1>(*sons[u].begin());
      fa[u] = v;
      sz[v] += sz[u];
      sum[v] += sum[u];
      sons[v].insert({-sz[u], u});
      son[v] = get<1>(*sons[v].begin());
      fa[v] = p;
      sons[p].erase({-sz[v], u});
      sons[p].insert({-sz[v], v});
      son[p] = get<1>(*sons[p].begin());
    }
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
