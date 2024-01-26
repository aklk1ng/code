#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

int sz;
std::vector<int> d;
std::vector<std::vector<int>> up, sl;

void cal(int v, int p) {
  d[v] = d[p] + 1;
  up[v][0] = p;
  for (int i = 1; i <= sz; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  for (auto &u : sl[v]) {
    if (u == p) {
      continue;
    }
    cal(u, v);
  }
};

void solve() {
  int n;
  std::cin >> n;
  sz = 0;
  while ((1 << sz) < n) {
    sz++;
  }
  d.assign(n, -1);
  up.assign(n, std::vector<int>(sz + 1));
  sl.assign(n, std::vector<int>());
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    sl[u].push_back(v);
    sl[v].push_back(u);
  }

  auto lca = [&](int u, int v) {
    if (d[u] < d[v]) {
      std::swap(u, v);
    }
    for (int i = sz; i >= 0; i--) {
      if (d[u] - (1 << i) >= d[v]) {
        u = up[u][i];
      }
    }
    for (int i = sz; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return u == v ? u : up[u][0];
  };
  cal(0, 0);
  int q;
  std::cin >> q;
  while (q--) {
    int k;
    std::cin >> k;
    std::vector<int> p(k);
    for (auto &e : p) {
      std::cin >> e;
      e--;
    }
    std::sort(p.begin(), p.end(), [](int a, int b) { return d[a] > d[b]; });
    std::vector<bool> used(k);
    for (int i = 0; i < k; i++) {
      if (lca(p[0], p[i]) == p[i]) {
        used[i] = true;
      }
    }
    int f = 0;
    while (f < k && used[f]) {
      f++;
    }
    if (f == k) {
      std::cout << "YES\n";
      continue;
    }
    bool ans = true;
    for (int i = f; i < k; i++) {
      if (lca(p[f], p[i]) == p[i]) {
        used[i] = true;
      }
    }
    for (auto e : used) {
      ans &= e;
    }
    ans &= d[lca(p[0], p[f])] <= d[p.back()];

    std::cout << (ans ? "YES" : "NO") << '\n';
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
