#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a(m);
  std::vector<int> op(n + 1);
  std::vector<std::vector<int>> del(n + 1);
  for (auto &e : a) {
    std::cin >> e.first >> e.second;
    op[e.first]++;
    del[e.second].emplace_back(e.first);
  }

  std::multiset<int> cur;
  std::vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (int j = 0; j < op[i]; j++) {
      cur.insert(i);
    }
    if (!cur.empty()) {
      dp[i] = std::max(dp[i], dp[*cur.begin() - 1] + (int)cur.size());
    }
    for (int &e : del[i]) {
      cur.erase(cur.find(e));
    }
  }
  std::cout << dp[n] << '\n';
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
