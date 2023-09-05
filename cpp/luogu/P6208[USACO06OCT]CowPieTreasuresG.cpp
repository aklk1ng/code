// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 110;
int dp[N][N];
int mp[N][N];

void solve() {
  int r, c;
  std::cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      std::cin >> mp[i][j];
    }
  }

  dp[1][1] = mp[1][1];
  for (int j = 2; j <= c; j++) {
    for (int i = 1; i <= j && i <= r; i++) {
      dp[i][j] = std::max(dp[i - 1][j - 1], std::max(dp[i][j - 1], dp[i + 1][j - 1])) + mp[i][j];
    }
  }
  std::cout << dp[r][c] << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
