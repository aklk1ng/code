#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  int timer = 0;
  std::vector<int> tin(n + 1), tout(n + 1), bit(n + 1), dep(n + 1);
  std::vector par(19, std::vector<int>(n + 1)), adj(n + 1, std::vector<int>());
  for (int i = 2; i <= n; i++) {
    std::cin >> par[0][i];
    adj[par[0][i]].push_back(i);
  }

  auto dfs = [&](auto self, int u) -> void {
    tin[u] = ++timer;
    dep[u] = dep[par[0][u]] + 1;
    for (int i = 1; i < 19; i++) {
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (int &v : adj[u]) {
      self(self, v);
    }
    tout[u] = timer;
  };
  auto add = [&](int u) {
    for (int i = tin[u]; i < n + 1; i += i & -i) {
      bit[i]++;
    }
  };
  auto get = [&](int u) {
    int res = 0;
    for (int i = tout[u]; i > 0; i -= i & -i) {
      res += bit[i];
    }
    for (int i = tin[u] - 1; i > 0; i -= i & -i) {
      res -= bit[i];
    }
    return res;
  };
  auto jmp = [&](int u, int d) {
    for (int i = 0; i < 19; i++) {
      if (d >> i & 1) {
        u = par[i][u];
      }
    }
    return u;
  };
  auto cover = [&](int u, int v) {
    return tin[u] <= tin[v] && tin[v] <= tout[u];
  };
  dfs(dfs, 1);
  add(1);
  int cur = 1, mx = 0;
  for (int u = 2; u <= n; u++) {
    add(u);
    if (cover(cur, u)) {
      int v = jmp(u, dep[u] - dep[cur] - 1);
      int sz = get(v);
      if (sz >= (u + 1) / 2) {
        cur = v;
        mx = u / 2;
      } else {
        mx = std::max(mx, sz);
      }
    } else {
      int sz = get(cur);
      if (sz < (u + 1) / 2) {
        cur = par[0][cur];
        mx = u / 2;
      } else {
        mx = std::max(mx, u - sz);
      }
    }
    std::cout << u - 2 * mx << " \n"[u == n];
  }
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
