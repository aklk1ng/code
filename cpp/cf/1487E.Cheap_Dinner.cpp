#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  std::vector<int> ns(4);
  for (int i = 0; i < 4; i++) {
    std::cin >> ns[i];
  }
  std::vector<std::vector<int>> cs(4);
  for (int i = 0; i < 4; i++) {
    cs[i].resize(ns[i]);
    for (int j = 0; j < ns[i]; j++) {
      std::cin >> cs[i][j];
    }
  }

  std::vector<std::vector<std::vector<int>>> bad;
  bad.resize(3, std::vector<std::vector<int>>());
  for (int i = 0; i < 3; i++) {
    bad[i].resize(ns[i + 1]);
    int m;
    std::cin >> m;
    for (int j = 0; j < m; j++) {
      int x, y;
      std::cin >> x >> y;
      x--, y--;
      bad[i][y].push_back(x);
    }
  }

  std::vector dp(4, std::vector<int>());
  dp[0] = cs[0];
  for (int i = 0; i < 3; i++) {
    dp[i + 1].resize(ns[i + 1]);
    std::multiset<int> s;
    for (int j = 0; j < ns[i]; j++) {
      s.insert(dp[i][j]);
    }
    for (int j = 0; j < ns[i + 1]; j++) {
      for (auto &k : bad[i][j]) {
        s.erase(s.find(dp[i][k]));
      }
      if (s.empty()) {
        dp[i + 1][j] = 4e8 + 43;
      } else {
        dp[i + 1][j] = *s.begin() + cs[i + 1][j];
      }
      for (auto &k : bad[i][j]) {
        s.insert(dp[i][k]);
      }
    }
  }

  int ans = *std::min_element(dp[3].begin(), dp[3].end());
  std::cout << (ans > 4e8 ? -1 : ans) << '\n';
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
