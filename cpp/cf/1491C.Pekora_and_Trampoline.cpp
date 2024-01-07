#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), cur(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll t = cur[i];
    if (t < a[i] - 1) {
      ans += a[i] - 1 - t;
      t += a[i] - 1 - t;
    }
    cur[i + 1] += t - a[i] + 1;
    if (i + 2 < n) {
      for (int j = i + 2; j < min(n, i + a[i] + 1); j++) {
        cur[j]++;
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
