#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 1e3 + 10;

char mp[N][N];
int n, h, w;

bool valid(int x, int y) { return x >= 1 && y >= 1 && x <= h && y <= w; }

void modify(int x, int y, int r) {
  int sx = x, sy = y - r;
  for (; sx > x - r && sy < y; sx--, sy++) {
    if (valid(sx, sy)) {
      mp[sx][sy] = '*';
    }
  }
  for (; sx < x && sy < y + r; sx++, sy++) {
    if (valid(sx, sy)) {
      mp[sx][sy] = '*';
    }
  }
  for (; sx < x + r && sy > y; sx++, sy--) {
    if (valid(sx, sy)) {
      mp[sx][sy] = '*';
    }
  }
  for (; sx > x && sy > y - r; sx--, sy--) {
    if (valid(sx, sy)) {
      mp[sx][sy] = '*';
    }
  }
}

void solve() {
  cin >> n >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      mp[i][j] = '_';
    }
  }
  for (int i = 1; i <= n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    modify(x, y, r);
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << mp[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
