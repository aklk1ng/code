#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
};

int mul(int x, int y) { return x * 1LL * y % mod; }

int pow(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) {
      z = mul(z, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector<int> suma(n + 1), sumb(n + 1);
  for (int i = 0; i < n; i++) {
    suma[i + 1] = suma[i] + a[i];
    sumb[i + 1] = sumb[i] + b[i];
  }
  int m = sumb[n];
  std::vector<int> f(m + 1), inv(m + 1);
  f[0] = 1;
  for (int i = 1; i <= m; i++) {
    f[i] = mul(f[i - 1], i);
  }
  inv[m] = pow(f[m], mod - 2);
  for (int i = m; i > 0; i--) {
    inv[i - 1] = mul(inv[i], i);
  }
  std::vector<int> sumc(m + 2);
  for (int i = 0; i <= m; i++) {
    sumc[i + 1] = add(sumc[i], mul(f[m], mul(inv[i], inv[m - i])));
  }
  int p = pow(pow(2, mod - 2), m);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    int k = 2 * (suma[r] - suma[l]) - suma[n];
    int cur = sumb[r] - sumb[l];
    int mx = std::max(0, std::min(k + cur, m + 1));
    int cnt = sumc[mx];
    std::cout << mul(cnt, p) << " \n"[q == 0];
  }
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
