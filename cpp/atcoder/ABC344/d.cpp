#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string t;
  std::cin >> t;
  int n;
  std::cin >> n;

  int tl = t.size();
  std::vector dp(105, std::vector<int>(105, 1e9));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 105; j++) {
      dp[i + 1][j] = dp[i][j];
    }
    int m;
    std::cin >> m;
    while (m > 0) {
      m--;
      std::string s;
      std::cin >> s;
      int sl = s.size();
      for (int j = 0; j + sl <= tl; j++) {
        bool ok = true;
        for (int k = 0; k < sl; k++) {
          if (t[j + k] != s[k]) {
            ok = false;
            break;
          }
        }

        if (ok) {
          dp[i + 1][j + sl] = std::min(dp[i + 1][j + sl], dp[i][j] + 1);
        }
      }
    }
  }

  std::cout << (dp[n][tl] > 5e8 ? -1 : dp[n][tl]) << '\n';
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
