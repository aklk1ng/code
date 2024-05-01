#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 100;

template <int mod>
inline unsigned int down(unsigned int x) {
  return x >= mod ? x - mod : x;
}

template <int mod>
struct Modint {
  unsigned int x;
  Modint() = default;

  Modint(unsigned int x) : x(x) {}

  friend std::istream &operator>>(std::istream &in, Modint &a) {
    return in >> a.x;
  }

  friend std::ostream &operator<<(std::ostream &out, Modint a) {
    return out << a.x;
  }

  friend Modint operator+(Modint a, Modint b) { return down<mod>(a.x + b.x); }

  friend Modint operator-(Modint a, Modint b) {
    return down<mod>(a.x - b.x + mod);
  }

  friend Modint operator*(Modint a, Modint b) { return 1ULL * a.x * b.x % mod; }

  friend Modint operator/(Modint a, Modint b) { return a * ~b; }

  friend Modint operator^(Modint a, int b) {
    Modint ans = 1;
    for (; b; b >>= 1, a *= a)
      if (b & 1)
        ans *= a;
    return ans;
  }

  friend Modint operator~(Modint a) { return a ^ (mod - 2); }

  friend Modint operator-(Modint a) { return down<mod>(mod - a.x); }

  friend Modint &operator+=(Modint &a, Modint b) { return a = a + b; }

  friend Modint &operator-=(Modint &a, Modint b) { return a = a - b; }

  friend Modint &operator*=(Modint &a, Modint b) { return a = a * b; }

  friend Modint &operator/=(Modint &a, Modint b) { return a = a / b; }

  friend Modint &operator^=(Modint &a, int b) { return a = a ^ b; }

  friend Modint &operator++(Modint &a) { return a += 1; }

  friend Modint operator++(Modint &a, int) {
    Modint x = a;
    a += 1;
    return x;
  }

  friend Modint &operator--(Modint &a) { return a -= 1; }

  friend Modint operator--(Modint &a, int) {
    Modint x = a;
    a -= 1;
    return x;
  }

  friend bool operator==(Modint a, Modint b) { return a.x == b.x; }

  friend bool operator!=(Modint a, Modint b) { return !(a == b); }
};

typedef Modint<mod> mint;

std::vector<mint> a(N), inv(N);

void init() {
  inv[0] = inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i];
  }
}

inline int lowbit(int x) { return x & -x; }

void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    mint mul = 1;
    for (int u = i + lowbit(i), d = 1; u <= n; u += lowbit(u), d++) {
      mul *= (d + k - 1) * inv[d];
      a[u] -= mul * a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  init();
  while (T--) {
    solve();
  }

  return 0;
}
