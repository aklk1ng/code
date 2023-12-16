#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, d, x;
  cin >> n >> d;
  vector<long double> w(n);
  long double ave = 0;
  vector dp(1 << 15, vector<long double>(n + 1));
  long double y;

  for (int i = 0; i < n; i++) {
    cin >> w[i];
    ave += w[i];
  }
  ave /= ((ll)d);
  for (int i = 0; i < (1 << n); i++) {
    y = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        y += w[j];
      }
    }
    dp[i][1] = pow(y - ave, 2);
    for (int j = 2; j <= d; j++) {
      dp[i][j] = dp[i][j - 1] + dp[0][1];
      x = i;
      while (x > 0) {
        dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + dp[x][1]);
        x = (x - 1) & i;
      }
    }
  }
  cout << setprecision(10) << (dp[(1 << n) - 1][d] / ((long double)d)) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
