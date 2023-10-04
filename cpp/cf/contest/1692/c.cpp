#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  vector<vector<char>> grid(9, vector<char>(9));
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 2; i <= 7; i++) {
    for (int j = 2; j <= 7; j++) {
      if (grid[i][j] == '#' && grid[i - 1][j + 1] == '#' && grid[i - 1][j - 1] == '#' &&
          grid[i + 1][j - 1] == '#' && grid[i + 1][j + 1] == '#') {
        cout << i << ' ' << j << '\n';
      }
    }
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
