// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

ll cal(ll x) { return x * (x - 1) / 2; }

void solve() {
  ll n;
  std::cin >> n;
  ll l = 0, r = 2e9;
  while (l + 1 < r) {
    ll mid = l + (r - l) / 2;
    if (cal(mid) <= n)
      l = mid;
    else
      r = mid;
  }
  std::cout << l + (n - l * (l - 1) / 2) << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
