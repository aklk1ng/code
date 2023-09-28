#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
#define ll long long
const int N = 5e3 + 5;

ll dp[N][N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n + 1);
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pre[i] = pre[i - 1] + p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (j - i + 1 > m) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + pre[j] - pre[j - m]);
      }
    }
  }
  cout << dp[k][n] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
