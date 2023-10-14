#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dp(n + 1, n);
  dp[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = dp[i + 1] + 1;
    if (i + a[i] < n) {
      dp[i] = min(dp[i], dp[i + a[i] + 1]);
    }
  }
  cout << dp[0] << '\n';
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
