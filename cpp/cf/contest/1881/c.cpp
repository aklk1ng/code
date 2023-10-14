#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      int sum = grid[i][j] + grid[j][n - 1 - i] + grid[n - 1 - i][n - 1 - j] + grid[n - 1 - j][i];
      int max = std::max(
          {grid[i][j], grid[j][n - 1 - i], grid[n - 1 - i][n - 1 - j], grid[n - 1 - j][i]});
      ans += max * 4 - sum;
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
