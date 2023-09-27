#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 1e3 + 10;

int n, m;
char mp[N][N];
int dist[N][N][4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
deque<int> q;

void add_front(int x, int y, int dir, int d) {
  if (d < dist[x][y][dir]) {
    q.push_front(x);
    q.push_front(y);
    q.push_front(dir);
  }
}

void add_back(int x, int y, int dir, int d) {
  if (d < dist[x][y][dir]) {
    q.push_back(dir);
    q.push_back(y);
    q.push_back(x);
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) {
        dist[i][j][k] = INF;
      }
    }
  }
  add_front(n - 1, m - 1, 3, 0);

  while (!q.empty()) {
    int x = q[0], y = q[1], dir = q[2];
    q.pop_front();
    q.pop_front();
    q.pop_front();
    int d = dist[x][y][dir];
    int nx = x + dx[dir], ny = y + dy[dir];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
      add_front(nx, ny, dir, d);
    }
    if (mp[x][y] == '#') {
      for (int i = 0; i < 4; i++) {
        if (i != dir) {
          add_back(x, y, i, d + 1);
        }
      }
    }
  }
  if (dist[0][0][3] == INF) {
    cout << -1 << '\n';
  } else {
    cout << dist[0][0][3] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
