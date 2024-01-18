#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

int n, k;
vector<vector<int>> g;
vector<int> st, pd;
vector<bool> used;

void init(int v, int d) {
  st.push_back(v);
  if (int(st.size()) - d >= 0) {
    pd[v] = st[(int)st.size() - d];
  }
  for (auto &u : g[v]) {
    init(u, d);
  }
  st.pop_back();
}

void dfs(int v) {
  used[v] = true;
  for (auto &u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}

int get(int d) {
  pd.assign(n, -1);
  init(0, d);

  vector<int> ord, h(n);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ord.push_back(v);
    for (auto &u : g[v]) {
      q.push(u);
      h[u] = h[v] + 1;
    }
  }
  reverse(ord.begin(), ord.end());

  used.assign(n, 0);
  int res = 0;
  for (auto &v : ord) {
    if (!used[v] && h[v] > d) {
      res++;
      dfs(pd[v]);
    }
  }
  return res;
}

void solve() {
  cin >> n >> k;
  g.assign(n, vector<int>());
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }

  int l = 1, r = n - 1;
  int ans = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (get(m) <= k) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  if (true) {
    cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
