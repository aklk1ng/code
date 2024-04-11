#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, b, x;
  std::cin >> n >> b >> x;
  int mx = 0;
  std::vector<int> c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
    mx = std::max(mx, c[i]);
  }

  auto cal = [&](ll a, ll k) -> ll {
    if (!a || !k) {
      return 0;
    }
    ll p = a / k;
    ll l = a % k;
    ll r = k - l;
    ll L = (p + 1) * l, R = p * r;
    return R * L + (R - p) * R / 2 + L * (L - p - 1) / 2;
  };
  std::vector<ll> pair(mx + 1), add(mx + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= c[i]; j++) {
      pair[j] += cal(c[i], j);
    }
    add[c[i]] += cal(c[i], c[i]);
  }

  ll ans = 0, other = 0;
  for (int i = 1; i <= mx; i++ ){
    ans = std::max(ans, 1LL * b * (pair[i] + other) - 1LL * x * (i - 1));
    other += add[i];
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
