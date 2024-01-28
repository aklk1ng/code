#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int mod = 998244353;

int vertex, edge, loop;
std::vector<std::vector<int>> g;
std::vector<bool> vis;
void dfs(int x) {
  if (vis[x]) {
    return;
  }
  vis[x] = true;
  vertex++;
  for (auto &y : g[x]) {
    edge++;
    dfs(y);
    if (y == x) {
      loop++;
    }
  }
};
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  vis.assign(n + 1, false);
  g.assign(n + 1, std::vector<int>());
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      continue;
    }
    vertex = 0;
    edge = 0;
    loop = 0;
    dfs(i);
    if (edge != 2 * vertex) {
      ans = 0;
    } else if (loop) {
      ans = 1LL * ans * n % mod;
    } else {
      ans = ans * 2 % mod;
    }
  }

  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
