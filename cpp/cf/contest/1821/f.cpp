#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  if (a < 0) {
    a += mod;
  }
  return a;
}

int mul(int a, int b) { return a * 1ll * b % mod; }

int pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> fa(2 * n + 1), rfa(2 * n + 1);
  fa[0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    fa[i] = mul(fa[i - 1], i);
  }
  rfa[2 * n] = pow(fa[2 * n], mod - 2);
  for (int i = 2 * n - 1; i >= 0; i--) {
    rfa[i] = mul(rfa[i + 1], i + 1);
  }
  auto cnk = [&](int i, int j) {
    if (j < 0 || i < 0 || j > i) {
      return 0;
    }
    return mul(fa[i], mul(rfa[j], rfa[i - j]));
  };
  auto snb = [&](int i, int j) { return cnk(i + j, j); };
  int p = 1, ans = 0;
  for (int i = m; i >= 0; i--) {
    int cur = 0;
    if (n - (m - i) * 1LL * (k + 1) - i * 1LL * (2 * k + 1) >= 0) {
      cur = mul(snb(n - (m - i) * (k + 1) - i * (2 * k + 1), m),
                mul(p, cnk(m, i)));
    }
    ans = add(ans, i & 1 ? -cur : cur);
    p = mul(p, 2);
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
