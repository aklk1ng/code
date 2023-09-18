#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1e5 + 5;

ll dp[N];
ll v[505], w[505];

void solve() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = v[i]; j <= m; j++) {
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[m] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
