#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  ll mx = 0, sum = 0, ans = 0;
  bool ok = false;
  map<ll, ll> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      if (ok) {
        ans += mx;
      } else {
        ans += m[0];
      }
      ok = true;
      mx = 0;
      m.clear();
    }
    sum += a[i];
    mx = max(mx, ++m[sum]);
  }
  if (ok) {
    ans += mx;
  } else {
    ans += m[0];
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
