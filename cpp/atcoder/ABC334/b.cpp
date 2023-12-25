#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll a, m, l, r;
  cin >> a >> m >> l >> r;
  l -= a, r -= a;
  int ans = 0;
  auto cal = [&](ll x) {
    ll t = (x % m + m) % m;
    return (x - t) / m;
  };
  cout << cal(r) - cal(l - 1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
