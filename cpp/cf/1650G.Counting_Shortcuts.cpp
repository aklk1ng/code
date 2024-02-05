#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n, m, s, t;
  std::cin >> n >> m;
  std::cin >> s >> t;
  std::vector<int> us(n + 1), dist(n + 1);
  std::vector dp(2, std::vector<int>(n + 1));
  for (int i = 0; i <= n; i++) {
    us[i] = dp[0][i] = dp[1][i] = 0;
    dist[i] = INT_MAX;
  }
  std::vector<std::vector<int>> g(n + 1);

  auto add = [&](int &a, int b) { a = (a + b) % mod; };
  auto bfs = [&]() {
    std::queue<std::tuple<int, int, int>> q;
    q.push({s, 0, 0});
    int ans = 0, mn = INT_MAX;
    us[s] = 1;
    dp[0][s] = 1;
    dist[s] = 0;
    while (!q.empty()) {
      auto [v, d, x] = q.front();
      q.pop();
      if (v == t) {
        if (mn == INT_MAX) {
          mn = d;
        }
        add(ans, dp[x][v]);
      }
      if (d == mn + 1) {
        continue;
      }
      for (auto &e : g[v]) {
        if (d <= dist[e]) {
          dist[e] = std::min(dist[e], d + 1);
          add(dp[d - dist[e] + 1][e], dp[x][v]);
          if (us[e] == 0 || (us[e] == 1 && dist[e] == d)) {
            q.push({e, d + 1, us[e]++});
          }
        }
      }
    }
    return ans;
  };
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  std::cout << bfs() << '\n';
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
