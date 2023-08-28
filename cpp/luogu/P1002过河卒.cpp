// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
const int N = 30;
ll dp[N][N];
std::bitset<N> mp[N];

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void solve() {
  int n, m, x, y;
  std::cin >> n >> m >> x >> y;
  n++, m++, x++, y++;

  mp[x][y] = true;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
      mp[nx][ny] = true;
  }
  dp[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1)
        continue;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      if (mp[i][j])
        dp[i][j] = 0;
    }
  }
  std::cout << dp[n][m] << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
