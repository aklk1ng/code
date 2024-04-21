#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  ll n, m, k;
  std::cin >> n >> m >> k;
  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll l, r;
  auto cal = [&](ll val) {
    while (l < n && a[l] < val) {
      l++;
    }
    while (r < n && a[r] <= val) {
      r++;
    }

    ll cur = r < k ? 0 : (val + a[r - k]) / 2 + 1;
    ll z = l + k - 1 >= n ? m : (a[l + k - 1] + val - 1) / 2;
    return std::max(0LL, z - cur + 1);
  };
  std::sort(a.begin(), a.end());
  a.push_back(m + 1);
  ll ans = cal(0), best = 0;
  for (int i = 0; i < n; i++) {
    ll cur = !i ? std::max(0LL, a[i] - 2) : std::max(a[i] - 2, a[i - 1] + 3);
    ll z = std::min(m, a[i] + 2);
    for (ll s = cur; s <= z; s++) {
      ll val = cal(s);
      if (val > ans) {
        ans = val;
        best = s;
      }
    }
  }
  std::cout << ans << ' ' << best << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
