#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  auto cal = [&](int si, int sj) -> ll {
    ll res = 0;
    int i = si - 1, j = sj - 1;
    while (i >= 1 && j >= 1) {
      res += grid[i--][j--];
    }
    i = si - 1, j = sj + 1;
    while (i >= 1 && j <= m) {
      res += grid[i--][j++];
    }
    i = si + 1, j = sj + 1;
    while (i <= n && j <= m) {
      res += grid[i++][j++];
    }
    i = si + 1, j = sj - 1;
    while (i <= n && j >= 1) {
      res += grid[i++][j--];
    }
    res += grid[si][sj];
    return res;
  };
  ll ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = max(ans, cal(i, j));
    }
  }
  cout << ans << '\n';
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
