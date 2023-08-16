// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

int grid[110][110][110];

void solve() {
  int n, m;
  std::cin >> n >> m;
  int a, b;
  int v = n * n * n;
  while (m--) {
    std::cin >> a >> b;
    for (int i = 1; i <= n; i++) {
      grid[a][b][i] = 1;
      grid[a][i][b] = 1;
      grid[i][a][b] = 1;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (grid[i][j][k] == 1)
          cnt++;

  std::cout << v - cnt << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
