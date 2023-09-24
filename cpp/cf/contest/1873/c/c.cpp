#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 1e5 + 5;

void solve() {
  vector<vector<int>> mp(11, vector<int>(11));
  vector<vector<char>> grid(11, vector<char>(11));
  int offset = 1;
  for (int _ = 1; _ <= 5; _++) {
    int i = offset, j = offset;
    for (; j <= 10 - offset; j++) {
      mp[i][j] = offset;
    }
    for (; i <= 10 - offset; i++) {
      mp[i][j] = offset;
    }
    for (; j > offset; j--) {
      mp[i][j] = offset;
    }
    for (; i > offset; i--) {
      mp[i][j] = offset;
    }
    offset++;
  }
  int ans = 0;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'X') {
        ans += mp[i][j];
      }
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
