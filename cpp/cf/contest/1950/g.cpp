#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> s(n), g(n);
  std::vector<std::string> aa(n), bb(n), vals;
  for (int i = 0; i < n; i++) {
    std::string a, b;
    std::cin >> a >> b;
    vals.push_back(a);
    vals.push_back(b);
    aa[i] = a;
    bb[i] = b;
  }
  std::sort(vals.begin(), vals.end());
  vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
  for (int i = 0; i < n; i++) {
    s[i] = std::lower_bound(vals.begin(), vals.end(), aa[i]) - vals.begin();
    g[i] = std::lower_bound(vals.begin(), vals.end(), bb[i]) - vals.begin();
  }
  std::vector dp(1 << n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 1;
  }
  for (int j = 0; j < (1 << n); j++) {
    for (int lst = 0; lst < n; lst++) {
      if (!dp[j][lst]) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (j >> i & 1) {
          continue;
        }
        if (s[lst] == s[i] || g[lst] == g[i]) {
          dp[j | (1 << i)][i] |= dp[j][lst];
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < (1 << n); j++) {
    for (int i = 0; i < n; i++) {
      if (dp[j][i]) {
        ans = std::max(ans, __builtin_popcount(j));
      }
    }
  }
  std::cout << n - ans << '\n';
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
