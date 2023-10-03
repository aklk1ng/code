#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];
set<int> s;
int n, a, b;

void dfs1(int u, int p, int x) {
  if (u == b) {
    return;
  }
  s.insert(x);
  for (auto &[v, w] : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs1(v, u, x ^ w);
  }
}

bool dfs2(int u, int p, int x) {
  if (u != b && s.count(x)) {
    return true;
  }
  for (auto &[v, w] : adj[u]) {
    if (v == p) {
      continue;
    }
    if (dfs2(v, u, x ^ w)) {
      return true;
    }
  }
  return false;
}

void solve() {
  cin >> n >> a >> b;
  a--, b--;
  s.clear();
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs1(a, -1, 0);
  if (dfs2(b, -1, 0)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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
