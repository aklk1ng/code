#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;

int n, m;
vector<vector<int>> mn1, mn2;
int dp[1 << 18][18];

int cal(int mask, int v) {
  if (dp[mask][v] != -1) {
    return dp[mask][v];
  }
  dp[mask][v] = 0;
  for (int u = 0; u < n; u++) {
    if (u != v && ((mask >> u) & 1)) {
      dp[mask][v] = max(dp[mask][v], min(mn1[u][v], cal(mask ^ (1 << v), u)));
    }
  }
  return dp[mask][v];
}

void solve() {
  cin >> n >> m;
  vector a(n, vector<int>(m));
  mn1.assign(n, vector<int>(n, 0));
  mn2.assign(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val = INF;
      for (int k = 0; k < m; k++) {
        val = min(val, abs(a[i][k] - a[j][k]));
      }
      mn1[i][j] = val;
      val = INF;
      for (int k = 0; k < m - 1; k++) {
        val = min(val, abs(a[i][k] - a[j][k + 1]));
      }
      mn2[i][j] = val;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(dp, -1, sizeof(dp));
    for (int j = 0; j < n; j++) {
      dp[1 << j][j] = (j == i ? INF : 0);
    }
    for (int j = 0; j < n; j++) {
      ans = max(ans, min(mn2[j][i], cal((1 << n) - 1, j)));
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
