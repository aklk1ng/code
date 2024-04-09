#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  ll a, b, r;
  std::cin >> a >> b >> r;

  auto get = [&](ll n, int i) { return n & (1LL << i); };
  ll x = 0;
  bool bit = true;
  if (a > b) {
    std::swap(a, b);
  }
  for (int i = 59; i >= 0; i--) {
    bool t1 = get(a, i);
    bool t2 = get(b, i);
    if (t1 != t2) {
      if (bit) {
        bit = false;
      } else {
        if (!t1 && x + (1LL << i) <= r) {
          x += 1LL << i;
          a ^= 1LL << i;
          b ^= 1LL << i;
        }
      }
    }
  }
  std::cout << b - a << '\n';
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
