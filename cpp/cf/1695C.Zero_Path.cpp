#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector grid(n, vector<int>(m)), mi(n, vector<int>(m)), mx(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  mx[0][0] = mi[0][0] = grid[0][0];
  for (int i = 1; i < n; i++) {
    mx[i][0] = mi[i][0] = mx[i - 1][0] + grid[i][0];
  }
  for (int j = 1; j < m; j++) {
    mx[0][j] = mi[0][j] = mx[0][j - 1] + grid[0][j];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + grid[i][j];
      mi[i][j] = min(mi[i - 1][j], mi[i][j - 1]) + grid[i][j];
    }
  }

  cout << (mx[n - 1][m - 1] % 2 || mi[n - 1][m - 1] > 0 || mx[n - 1][m - 1] < 0 ? "No" : "Yes")
       << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
