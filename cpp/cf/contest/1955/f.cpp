#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;
const int N = 201;

std::vector dp(N, std::vector(N, std::vector<int>(N)));

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        int pre = 0;
        if (i) {
          pre = std::max(pre, dp[i - 1][j][k]);
        }
        if (j) {
          pre = std::max(pre, dp[i][j - 1][k]);
        }
        if (k) {
          pre = std::max(pre, dp[i][j][k - 1]);
        }
        dp[i][j][k] = pre;
        int xr = ((i & 1) * 1) ^ ((j & 1) * 2) ^ ((k & 1) * 3);
        if (!xr && (i || j || k)) {
          dp[i][j][k]++;
        }
      }
    }
  }
}

void solve() {
  std::vector<int> p(4);
  for (int i = 0; i < 4; i++) {
    std::cin >> p[i];
  }
  std::cout << dp[p[0]][p[1]][p[2]] + p[3] / 2 << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  init();
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
