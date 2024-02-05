#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::cin >> s;

  std::vector<ll> dp(n + 1);
  std::multiset<ll> mis, vals;
  mis.insert(0);
  std::vector del(n, std::vector<ll>());
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = i + 1 + dp[i + 1];
    if (i + k + 2 <= n) {
      mis.erase(mis.find(dp[i + k + 2]));
    }
    for (auto &e : del[i]) {
      vals.erase(vals.find(e));
    }
    if (!vals.empty()) {
      dp[i] = std::min(dp[i], *vals.begin());
    }
    if (s[i] == '1') {
      ll val = mis.empty() ? 0 : *mis.begin() + i + 1;
      dp[i] = std::min(dp[i], val);
      vals.insert(val);
      if (i - k - 1 >= 0) {
        del[i - k - 1].push_back(val);
      }
    }
    mis.insert(dp[i]);
  }
  std::cout << dp[0] << '\n';
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
