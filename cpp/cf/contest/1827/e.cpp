#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 5e5 + 5;

std::vector rm(19, std::vector<int>());
std::vector<int> tin(N), par(N), val(N);

void solve() {
  int n, m;
  std::cin >> n >> m;
  int timer = 0;
  std::vector adj(N, std::vector<int>()), trip(N, std::vector<int>());
  std::vector<int> path, leaf, topo;
  rm[0].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    if (adj[u].size() == 1) {
      trip[u].push_back(v);
    }
    if (adj[v].size() == 1) {
      trip[v].push_back(u);
    }
  }

  if (n == 1) {
    std::cout << "YES\n";
    return;
  }
  auto dfs = [&](auto self, int u) -> void {
    topo.push_back(u);
    tin[u] = timer++;
    for (int &v : adj[u]) {
      if (v != par[u]) {
        path.push_back(u);
        rm[0].push_back(tin[u]);
        par[v] = u;
        self(self, v);
      }
    }
  };
  auto get = [&](int l, int r) {
    int k = 31 - __builtin_clz(r - l);
    return std::min(rm[k][l], rm[k][r - (1 << k)]);
  };
  auto lca = [&](int u, int v) {
    if (u == v) {
      return u;
    }
    std::tie(u, v) = std::minmax(tin[u], tin[v]);
    return path[get(u, v)];
  };
  auto reroot = [&](int r, int u, int v) {
    return lca(r, u) ^ lca(r, v) ^ lca(u, v);
  };
  auto cal = [&]() {
    for (int &u : topo) {
      for (int &v : adj[u]) {
        if (v != par[u]) {
          val[u] += val[v];
        }
      }
    }
  };
  auto add = [&](int u) {
    for (int &v : trip[u]) {
      if (v < 0) {
        val[-v]--;
      } else {
        val[v]++;
      }
    }
  };
  auto check = [&](int l) {
    for (int u = 1; u <= n; u++) {
      val[u] = 0;
    }
    for (int i = 0; i < l; i++) {
      add(leaf[i]);
    }
    cal();
    for (int u = 1; u <= n; u++) {
      if (val[u] == l) {
        return true;
      }
    }
    return false;
  };
  dfs(dfs, 1);
  std::reverse(topo.begin(), topo.end());
  for (int k = 1; (1 << k) <= n; k++) {
    rm[k].resize(n - (1 << k) + 1);
    for (int i = 0; i + (1 << k) <= n; i++) {
      rm[k][i] = std::min(rm[k - 1][i], rm[k - 1][i + (1 << (k - 1))]);
    }
  }
  for (int u = 1; u <= n; u++) {
    if (adj[u].size() == 1) {
      leaf.push_back(u);
      trip[u].push_back(u);
      std::sort(trip[u].begin(), trip[u].end(),
                [&](int x, int y) { return tin[x] < tin[y]; });
      int l = trip[u].size();
      for (int i = 0; i + 1 < l; i++) {
        trip[u].push_back(-lca(trip[u][i], trip[u][i + 1]));
      }
      trip[u].push_back(-par[lca(trip[u][0], trip[u][l - 1])]);
    }
  }
  int l = 0;
  for (int k = 18; k >= 0; k--) {
    if (l + (1 << k) <= leaf.size() && check(l + (1 << k))) {
      l += 1 << k;
    }
  }
  if (l == leaf.size()) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
  for (int u = 1; u <= n; u++) {
    val[u] = 0;
  }
  add(leaf[l]);
  cal();
  for (int &u : leaf) {
    bool ok = false;
    for (int &v : trip[u]) {
      if (v <= 0) {
        break;
      }
      if (val[reroot(leaf[l], u, v)]) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      std::cout << leaf[l] << ' ' << u << '\n';
      return;
    }
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
