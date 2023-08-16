// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[1010][1010];
int signs[1010][1010];

int n, m;
int cnt;

void dfs(int x, int y) {
  if (map[x][y] == '#' || x < 0 || y < 0 || x > n - 1 || y > m - 1 || signs[x][y] == 1)
    return;
  signs[x][y] = 1;
  if (map[x][y] == '!')
    cnt++;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    dfs(xx, yy);
  }
}

void solve() {
  std::cin >> n >> m;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> map[i][j];
      if (map[i][j] == '@') {
        x = i;
        y = j;
      }
    }
  }
  dfs(x, y);
  std::cout << cnt << std::endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
