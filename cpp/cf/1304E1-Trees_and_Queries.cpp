#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

std::vector<std::vector<int>> adj(N);
std::vector<int> depth(N);
std::vector par(N, std::vector<int>(18));

void build(int cur, int p) {
  depth[cur] = depth[p] + 1;
  par[cur][0] = p;
  for (int i = 1; i <= 17; i++) {
    par[cur][i] = par[par[cur][i - 1]][i - 1];
  }
  for (auto &e : adj[cur]) {
    if (e != p) {
      build(e, cur);
    }
  }
};

int len(int a, int b) {
  int cur = 0;
  if (depth[a] > depth[b]) {
    std::swap(a, b);
  }
  for (int i = 17; i >= 0; i--) {
    if (depth[par[b][i]] >= depth[a]) {
      b = par[b][i];
      cur += 1 << i;
    }
  }
  if (a == b) {
    return cur;
  }
  for (int i = 17; i >= 0; i--) {
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
      cur += 1 << (i + 1);
    }
  }
  return cur + 2;
}

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build(1, 0);

  int q;
  std::cin >> q;
  while (q--) {
    int x, y, a, b, k;
    std::cin >> x >> y >> a >> b >> k;
    int t = len(a, b);
    int with = std::min(len(a, x) + len(y, b), len(a, y) + len(x, b)) + 1;
    int ans = INF;
    if (t % 2 == k % 2) {
      ans = t;
    }
    if (with % 2 == k % 2) {
      ans = std::min(ans, with);
    }

    std::cout << (ans <= k ? "YES" : "NO") << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
