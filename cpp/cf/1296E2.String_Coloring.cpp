#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  std::vector<int> mx(26), dp(n, 1);
  for (int i = 0; i < n; i++) {
    for (int c = 25; c > s[i] - 'a'; c--) {
      dp[i] = std::max(dp[i], mx[c] + 1);
    }
    mx[s[i] - 'a'] = std::max(mx[s[i] - 'a'], dp[i]);
  }

  std::cout << *std::max_element(mx.begin(), mx.end()) << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << dp[i] << " \n"[i == n - 1];
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
