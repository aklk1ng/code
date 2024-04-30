#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

template <int MOD>
struct ModInt {
  unsigned x;

  ModInt() : x(0) {}

  ModInt(signed sig) : x(sig) {}

  ModInt(signed long long sig) : x(sig % MOD) {}

  int get() const { return (int)x; }

  ModInt pow(ll p) {
    ModInt res = 1, a = *this;
    while (p) {
      if (p & 1)
        res *= a;
      a *= a;
      p >>= 1;
    }
    return res;
  }

  ModInt &operator+=(ModInt that) {
    if ((x += that.x) >= MOD)
      x -= MOD;
    return *this;
  }

  ModInt &operator-=(ModInt that) {
    if ((x += MOD - that.x) >= MOD)
      x -= MOD;
    return *this;
  }

  ModInt &operator*=(ModInt that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }

  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }

  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }

  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }

  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

  bool operator<(ModInt that) const { return x < that.x; }

  friend std::ostream &operator<<(std::ostream &os, ModInt a) {
    os << a.x;
    return os;
  }
};

typedef ModInt<998244353> mint;

void solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::cin >> a >> b;

  mint two = 2;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cnt++;
    }
  }
  std::vector<mint> dp(n + 2);
  dp[0] = two.pow(n);
  dp[1] = dp[0] - 1;
  dp[0] = 0;
  for (int i = 2; i < n; i++) {
    mint x = i - 1;
    x /= n;
    dp[i] = (dp[i - 1] - x * dp[i - 2] - 1) * n / (n - i + 1);
  }
  dp[n] = dp[n - 1] + 1;
  std::cout << dp[cnt] << '\n';
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
