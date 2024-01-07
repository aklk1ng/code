#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
const int INF = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> dp(N);
  vector dp2(505, vector<int>(505));
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int d = 1; d <= 500; d++) {
      dp[i] += dp2[d][i % d];
      if (dp[i] >= mod) {
        dp[i] -= mod;
      }
    }

    if (x <= 500) {
      dp2[x][i % x] += dp[i];
      if (dp2[x][i % x] >= mod) {
        dp2[x][i % x] -= mod;
      }
    } else {
      for (int j = i + x; j < n; j += x) {
        dp[j] += dp[i];
        if (dp[j] >= mod) {
          dp[j] -= mod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i];
    if (ans >= mod) {
      ans -= mod;
    }
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
