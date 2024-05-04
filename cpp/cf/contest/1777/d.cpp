#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> edges(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  std::vector<int> P(n);
  auto cal = [&](ll a, ll b) {
    ll res = 1;
    while (b) {
      if (b & 1) {
        res *= a;
        res %= mod;
      }
      a *= a;
      a %= mod;
      b >>= 1;
    }
    return res;
  };
  auto dfs = [&](auto self, int v, int p, int dep) -> int {
    int cur = dep;
    for (auto &u : edges[v]) {
      if (u != p) {
        cur = std::max(self(self, u, v, dep + 1), cur);
      }
    }
    P[v] = cur - dep + 1;
    return cur;
  };
  dfs(dfs, 0, 0, 0);
  ll p = cal(2, n - 1), ans = 0;
  for (int i = 0; i < n; i++) {
    ans += p * P[i] % mod;
    ans %= mod;
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
