#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  vector<vector<char>> grid(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  if (grid[r][c] == 'B') {
    cout << 0 << '\n';
    return;
  }
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (grid[i][j] == 'B') {
        flag = true;
        break;
      }
    }
  }
  if (!flag) {
    cout << -1 << '\n';
    return;
  }

  for (int j = 1; j <= m; j++) {
    if (grid[r][j] == 'B') {
      cout << 1 << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (grid[i][c] == 'B') {
      cout << 1 << '\n';
      return;
    }
  }
  cout << 2 << '\n';
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
