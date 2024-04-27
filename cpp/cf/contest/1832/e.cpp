#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int x, int y, int p = mod) { return ((x + y) % p + p) % p; }

int mul(int x, int y, int p = mod) { return (x * 1LL * y) % p; }

int pow(int x, int y, int p = mod) {
  int res = add(1, 0, mod);
  while (y > 0) {
    if (y % 2) {
      res = mul(res, x, mod);
    }
    y /= 2;
    x = mul(x, x, mod);
  }
  return res;
}

auto psum(std::vector<int> v) {
  std::vector<int> res(1, 0);
  for (auto &e : v) {
    res.push_back(add(res.back(), e));
  }
  return res;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::cin >> a[0];
  int x, y, m, k;
  std::cin >> x >> y >> m >> k;

  for (int i = 1; i < n; i++) {
    a[i] = add(mul(a[i - 1], x, m), y, m);
  }
  for (int i = 0; i <= k; i++) {
    a = psum(a);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans ^= (a[i + 1] * 1LL * i);
  }
  std::cout << ans << '\n';
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
