#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= r) {
      break;
    }
    int t1 = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
    int t2 = upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
    t1 = max(t1, i + 1);
    if (t2 < t1) {
      break;
    }
    ans += t2 - t1;
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
