#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 7;
const int N = 3e5 + 5;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector dp(N, vector<vector<ll>>(3, vector<ll>(3)));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][k] = -INF;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (k < 2) {
          dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
        }
        if (j < 2) {
          dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
        }
        if (i < n) {
          dp[i + 1][j][k] =
              max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * ll(k == 1 ? x : 1));
        }
      }
    }
  }
  cout << dp[n][2][2] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  if (false) {
    cin >> tt;
  }
  while (tt--) {
    solve();
  }

  return 0;
}
