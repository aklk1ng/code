#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, K, d;
  cin >> n >> K >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector dp(n + 1, vector(K + 1, vector<ll>(d, -1)));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < K + 1; j++) {
      for (int k = 0; k < d; k++) {
        if (dp[i][j][k] == -1) {
          continue;
        }
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        if (j != K) {
          dp[i + 1][j + 1][(k + a[i]) % d] =
              max(dp[i + 1][j + 1][(k + a[i]) % d], dp[i][j][k] + a[i]);
        }
      }
    }
  }
  cout << dp[n][K][0] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
