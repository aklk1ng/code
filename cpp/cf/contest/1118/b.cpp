#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int epref = 0, opref = 0, esuf = 0, osuf = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i & 1) {
      esuf += a[i];
    } else {
      osuf += a[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      esuf -= a[i];
    } else {
      osuf -= a[i];
    }
    if (epref + osuf == opref + esuf) {
      ans++;
    }
    if (i & 1) {
      epref += a[i];
    } else {
      opref += a[i];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
