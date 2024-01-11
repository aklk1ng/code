#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int ans = 0;
  vector val(n, vector<int>(n));
  vector sum(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 1) {
        for (int k = max(0, j - 1); k <= min(j + 1, n - 1); k++) {
          sum[i][j] ^= sum[i - 1][k];
        }
      } else if (i == 0) {
      } else {
        if (j == 0) {
          sum[i][j] ^= sum[i - 2][j];
        } else {
          sum[i][j] ^= sum[i - 1][j - 1];
        }
        if (j == n - 1) {
          sum[i][j] ^= sum[i - 2][j];
        } else {
          sum[i][j] ^= sum[i - 1][j + 1];
        }
        sum[i][j] ^= sum[i - 2][j];
        sum[i][j] ^= val[i - 1][j];
      }
      if (sum[i][j] ^ (s[i][j] - '0')) {
        ans++;
        sum[i][j] ^= 1;
        val[i][j] = 1;
      }
    }
  }
  cout << ans << '\n';
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
