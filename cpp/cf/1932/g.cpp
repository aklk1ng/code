#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 1e18;

struct triple {
  ll d, x, y;
};

triple eucl(ll a, ll b) {
  if (!b) {
    return {a, 1, 0};
  }
  ll k = a / b;
  auto [d, x, y] = eucl(b, a - k * b);
  return {d, y, x - k * y};
}

void solve() {
  int n, m, H;
  std::cin >> n >> m >> H;
  std::vector<ll> l(n), s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  std::vector<ll> d(n, INF);
  d[0] = 0;
  std::set<std::pair<ll, int>> q;
  q.insert({d[0], 0});
  while (!q.empty()) {
    auto p = *q.begin();
    q.erase(p);
    int v = p.second;
    ll t = d[v];
    for (auto &u : g[v]) {
      ll a = (l[v] + (t % H) * s[v]) - (l[u] + (t % H) * s[u]);
      a %= H;
      if (a < 0) {
        a += H;
      }
      ll b = s[u] - s[v];
      b %= H;
      if (b < 0) {
        b += H;
      }
      auto [dd, x, y] = eucl(b, H);
      if (a % dd) {
        continue;
      }
      x *= a / dd;
      x %= (H / dd);
      if (x < 0) {
        x += H / dd;
      }
      ll dt = x;
      if (d[v] + dt + 1 < d[u]) {
        q.erase({d[u], u});
        d[u] = d[v] + dt + 1;
        q.insert({d[u], u});
      }
    }
  }

  std::cout << (d[n - 1] == INF ? -1 : d[n - 1]) << '\n';
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
