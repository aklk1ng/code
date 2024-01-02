#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector cnt(26, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      cnt[j][i + 1] = cnt[j][i];
    }
    cnt[a[i] - 1][i + 1]++;
  }

  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans = max(ans, cnt[i][n - 1]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int in = 0, out = 0;
      for (int k = 0; k < 26; k++) {
        in = max(in, cnt[k][j + 1] - cnt[k][i]);
        out = max(out, min(cnt[k][i], cnt[k][n] - cnt[k][j + 1]) * 2);
      }
      ans = max(ans, in + out);
    }
  }
  cout << ans << '\n';
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
