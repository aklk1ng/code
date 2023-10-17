#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> cnt(2, vector<int>(n + 1));
  cnt[0][0] = 0;
  cnt[1][0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[0][i + 1] = cnt[0][i] + (a[i] == 0 ? 1 : 0);
    cnt[1][i + 1] = cnt[1][i] + (a[i] == 1 ? 1 : 0);
  }
  int ans = n - 1;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, max(cnt[1][i], cnt[0][n] - cnt[0][i]));
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
