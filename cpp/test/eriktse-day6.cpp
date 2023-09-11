// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1010;

int mp[N][N];
int d[N][N];
int n, m;
bitset<N> vis[N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  d[sx][sy] = 0;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (vis[x][y])
      continue;
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !mp[nx][ny] && d[nx][ny] > d[x][y] + 1) {
        d[nx][ny] = d[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  memset(d, 0x3f, sizeof(d));
  bfs(1, 1);
  if (!vis[n][m])
    cout << -1 << '\n';
  else
    cout << d[n][m] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }
  solve();

  return 0;
}
