#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
    }
  }

  int ans = 0;
  vector<vector<int>> vis(h, vector<int>(w));
  auto bfs = [&](int sx, int sy) {
    vis[sx][sy] = 1;
    queue<pair<int, int>> q;
    q.push({sx, sy});

    while (!q.empty()) {
      int nx = q.front().first, ny = q.front().second;
      q.pop();
      for (int i = 0; i < 8; i++) {
        int x = nx + dx[i], y = ny + dy[i];
        if (x >= 0 && x < h && y >= 0 && y < w && !vis[x][y] && s[x][y] == '#') {
          vis[x][y] = 1;
          q.push({x, y});
        }
      }
    }
  };

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!vis[i][j] && s[i][j] == '#') {
        bfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
