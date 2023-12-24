#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int n, K;
vector dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
int cal(int cur, int i, int dir) {
  if (i == 1) {
    return 1;
  }
  if (dp[cur][i][dir] != -1) {
    return dp[cur][i][dir];
  }

  int ans = 2;
  if (dir == 1) {
    if (cur < n) {
      ans += cal(cur + 1, i, dir) - 1;
    }
    ans %= mod;
    if (cur > 1) {
      ans += cal(cur - 1, i - 1, 1 - dir) - 1;
    }
    ans %= mod;
    dp[cur][i][dir] = ans;
  } else {
    if (cur > 1) {
      ans += cal(cur - 1, i, dir) - 1;
    }
    ans %= mod;
    if (cur < n) {
      ans += cal(cur + 1, i - 1, 1 - dir) - 1;
    }
    ans %= mod;
    dp[cur][i][dir] = ans;
  }
  return ans;
}

void solve() {
  cin >> n >> K;
  for (int i = 0; i < (int)dp.size(); i++) {
    for (int j = 0; j < (int)dp[i].size(); j++) {
      for (int k = 0; k < (int)dp[i][j].size(); k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << cal(1, K, 1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
