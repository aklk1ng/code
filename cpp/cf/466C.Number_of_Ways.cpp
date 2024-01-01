#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  ll s = 0;
  vector<int> a(n), cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % 3) {
    cout << 0 << '\n';
  } else {
    s /= 3;
    ll ss = 0;
    for (int i = n - 1; i >= 0; i--) {
      ss += a[i];
      if (ss == s) {
        cnt[i] = 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      cnt[i] += cnt[i + 1];
    }
    ll ans = 0;
    ss = 0;
    for (int i = 0; i < n - 2; i++) {
      ss += a[i];
      if (ss == s) {
        ans += cnt[i + 2];
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
