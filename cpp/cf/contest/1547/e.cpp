#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k), t(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> t[i];
  }

  vector<ll> c(n, INT_MAX), l(n, INT_MAX), r(n, INT_MAX);
  for (int i = 0; i < k; i++) {
    c[a[i] - 1] = t[i];
  }

  ll p;
  p = INT_MAX;
  for (int i = 0; i < n; i++) {
    p = min(p + 1, c[i]);
    l[i] = p;
  }
  p = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    p = min(p + 1, c[i]);
    r[i] = p;
  }

  for (int i = 0; i < n; i++) {
    cout << min(l[i], r[i]) << " \n"[i == n - 1];
  }
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
