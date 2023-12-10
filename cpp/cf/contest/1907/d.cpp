#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> seg;
  for (int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;
    seg.push_back({l, r});
  }

  auto check = [&](ll x) {
    ll mi = 0, mx = 0;
    for (auto &[k, v] : seg) {
      mi = max(mi - x, k);
      mx = min(mx + x, v);
      if (mi > mx) {
        return false;
      }
    }
    return true;
  };
  ll l = -1, r = 1e9;
  while (l + 1 != r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << '\n';
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
