#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 2e18;

struct PathParams {
  ll num;
  int money;
};
bool operator==(const PathParams &a, const PathParams &b) {
  return std::tie(a.num, a.money) == std::tie(b.num, b.money);
}
bool operator!=(const PathParams &a, const PathParams &b) { return !(a == b); }
bool operator<(const PathParams &a, const PathParams &b) {
  if (a.num != b.num)
    return a.num < b.num;
  return a.money > b.money;
}

struct State {
  PathParams params;
  int v;
  int best;
};
bool operator<(const State &a, const State &b) {
  return std::tie(a.params, a.v, a.best) < std::tie(b.params, b.v, b.best);
}
bool operator>(const State &a, const State &b) { return !(a < b); }

void solve() {
  int n, m, p;
  std::cin >> n >> m >> p;
  std::vector dp(n, std::vector<PathParams>(n, {INF, 0}));
  std::vector<std::vector<std::pair<int, int>>> g(n);
  std::vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b, s;
    std::cin >> a >> b >> s;
    a--, b--;
    g[a].emplace_back(b, s);
  }
  dp[0][0] = {0, p};
  std::priority_queue<State, std::vector<State>, std::greater<>> pq;
  pq.push({.params = {.num = 0, .money = p}, .v = 0, .best = 0});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    int v = cur.v;
    int best = cur.best;
    if (dp[v][best] != cur.params)
      continue;
    for (auto &[u, s] : g[v]) {
      auto t = cur;
      PathParams &path = t.params;
      if (path.money < s) {
        ll need = (s - path.money + w[best] - 1) / w[best];
        path.num += need;
        path.money += need * w[best];
      }
      path.money -= s;
      t.v = u;
      if (w[u] > w[t.best]) {
        t.best = u;
      }
      if (path < dp[u][t.best]) {
        dp[u][t.best] = path;
        pq.push(t);
      }
    }
  }

  ll ans = INF;
  for (int i = 0; i < n; i++) {
    ans = std::min(ans, dp[n - 1][i].num);
  }
  std::cout << (ans == INF ? -1 : ans) << '\n';
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
