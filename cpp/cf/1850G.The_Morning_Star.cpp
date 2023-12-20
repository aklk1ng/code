#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  map<ll, ll> up, side, diag1, diag2;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    up[x]++;
    side[y]++;
    diag1[x - y]++;
    diag2[x + y]++;
  }
for (auto &e : up) {
    ans += e.second * (e.second - 1);
  }
  for (auto &e : side) {
    ans += e.second * (e.second - 1);
  }
  for (auto &e : diag1) {
    ans += e.second * (e.second - 1);
  }
  for (auto &e : diag2) {
    ans += e.second * (e.second - 1);
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
