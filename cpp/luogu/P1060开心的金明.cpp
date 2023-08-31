// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 1e5 + 5;
int v[30], w[30];
// int dp[30][N]; // dp[i][j] 表示到第i个物品为止,总价值不超过j的最大值
int dp[N];

// void solve() {
//   int n, m;
//   std::cin >> n >> m;
//   for (int i = 1; i <= m; i++)
//     std::cin >> v[i] >> w[i];
//   for (int i = 1; i <= m; i++) {
//     for (int j = 0; j <= n; j++) {
//       if (j < v[i])
//         dp[i][j] = dp[i - 1][j];
//       else
//         dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i] * w[i]);
//     }
//   }
//   std::cout << dp[m][n] << '\n';
// }

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++)
    std::cin >> v[i] >> w[i];
  for (int i = 1; i <= m; i++) {
    for (int j = v[i]; j <= n; j++) {
      dp[j] = std::max(dp[j], dp[j - v[i]] + v[i] * w[i]);
    }
  }
  std::cout << dp[n] << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
