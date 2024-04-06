#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  n %= m;
  int a = n / std::__gcd(n, m), b = m / std::__gcd(n, m);
  if (__builtin_popcount(b) > 1) {
    std::cout << "-1\n";
  } else {
    std::cout << 1LL * __builtin_popcount(a) * m - n << '\n';;
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
  while (T--) {
    solve();
  }

  return 0;
}
