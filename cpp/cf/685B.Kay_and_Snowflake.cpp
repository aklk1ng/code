#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

set<pair<int, int>> cal(const vector<vector<int>> &graph, vector<int> &ans,
                        int v) {
  set<pair<int, int>> s;
  for (auto &u : graph[v]) {
    auto it = cal(graph, ans, u);
    if ((int)it.size() >= (int)s.size()) {
      swap(it, s);
    }
    for (auto &e : it) {
      s.insert(e);
    }
  }
  int sz = s.size() + 1;
  s.emplace(sz, v);
  ans[v] = s.lower_bound({(sz + 1) / 2, 0})->second;

  return s;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    graph[x - 1].push_back(i);
  }
  vector<int> ans(n, INT_MAX);
  cal(graph, ans, 0);

  while (q--) {
    int x;
    cin >> x;
    cout << ans[x - 1] + 1 << '\n';
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
