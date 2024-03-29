#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e5 + 5;
const int INF = 1e9;

std::vector adj(N, std::vector<int>());
std::vector dp(N, std::vector<int>(3));

void solve() {
  int n;
  std::cin >> n;

  auto dfs = [&](auto self, std::string &s, int u) -> void {
    dp[u][0] = INF;
    if (s[u] != 'S') {
      dp[u][1] = 0;
    } else {
      dp[u][1] = INF;
    }
    if (s[u] != 'P') {
      dp[u][2] = 0;
    } else {
      dp[u][2] = INF;
    }

    int tot = 0;
    for (int &v : adj[u]) {
      self(self, s, v);
      dp[u][1] = dp[u][1] + std::min({dp[v][1], dp[v][2] + 1, dp[v][0]});
      dp[u][2] = dp[u][2] + std::min({dp[v][2], dp[v][1] + 1, dp[v][0]});
      tot += dp[v][0];
    }

    if (s[u] != 'C') {
      tot = INF;
    }
    dp[u][0] = std::min({tot, dp[u][1] + 1, dp[u][2] + 1});
  };
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    adj[x].push_back(i);
  }

  std::string s;
  std::cin >> s;
  s = '0' + s;
  dfs(dfs, s, 1);

  std::cout << std::min({dp[1][0], dp[1][1], dp[1][2]}) << '\n';
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
