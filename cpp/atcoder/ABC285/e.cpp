#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = b[i - 1] + a[(i + 1) / 2];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -INF));
  dp[1][0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] < 0) {
        continue;
      }
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + b[j]);
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[n][i] + b[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
