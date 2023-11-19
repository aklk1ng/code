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
  ll ans = -1;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      ll mx = -1e18, mi = 1e18;
      for (int j = 0; j < n; j += i) {
        ll sum = 0;
        for (int k = j; k < i + j; k++) {
          sum += a[k];
        }
        mx = max(mx, sum);
        mi = min(mi, sum);
      }
      ans = max(ans, mx - mi);
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
