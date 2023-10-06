#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, k;
  cin >> n >> k;
  if (2 * k - 1 <= n) {
    vector<vector<char>> grid(n + 1, vector<char>(n + 1, '.'));
    int i = 1, j = 1;
    while (k--) {
      grid[i][j] = 'R';
      i += 2;
      j += 2;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << grid[i][j];
      }
      cout << '\n';
    }
  } else {
    cout << -1 << '\n';
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
