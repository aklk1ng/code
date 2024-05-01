#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int N = 2e5 + 5;
std::vector g(N, std::vector<int>());
std::vector<int> d(N), par(N);
std::vector<bool> vis(N);

void dfs(int v, int p, int depth) {
  d[v] = depth;
  par[v] = p;
  for (auto &e : g[v]) {
    if (e != p) {
      dfs(e, v, depth + 1);
    }
  }
};

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0, 0, 0);
  int v1 = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] > d[v1]) {
      v1 = i;
    }
  }
  dfs(v1, v1, 0);
  int v2 = v1;
  for (int i = 0; i < n; i++) {
    if (d[i] > d[v2]) {
      v2 = i;
    }
  }

  std::vector<int> t;
  for (int v = v2; v != v1; v = par[v]) {
    vis[v] = true;
    t.push_back(v);
  }
  vis[v1] = true;
  t.push_back(v1);
  std::reverse(t.begin(), t.end());
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    if (!vis[par[i]]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
  std::vector<int> ans;
  for (int i = 0; i < t.size(); i += 2) {
    ans.push_back(t[i]);
    if (i + 1 != t.size()) {
      for (auto &e : g[t[i + 1]]) {
        if (!vis[e]) {
          ans.push_back(e);
        }
      }
    }
  }
  if (t.size() % 2 == 0) {
    for (int i = t.size() - 1; i > 0; i -= 2) {
      ans.push_back(t[i]);
      if (i - 1 >= 0) {
        for (auto &e : g[t[i - 1]]) {
          if (!vis[e]) {
            ans.push_back(e);
          }
        }
      }
    }
  } else {
    for (int i = t.size() - 1; i > 0; i -= 2) {
      ans.push_back(t[i - 1]);
      if (i - 2 >= 0) {
        for (auto &e : g[t[i - 2]]) {
          if (!vis[e]) {
            ans.push_back(e);
          }
        }
      }
    }
  }

  for (auto &e : ans) {
    std::cout << e + 1 << ' ';
  }
  std::cout << '\n';
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
