#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2, 1), b(n + 2, 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  auto lcm = [&](int x, int y) { return x * y / std::__gcd(x, y); };
  for (int i = 1; i <= n + 1; i++) {
    b[i] = lcm(a[i], a[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (std::__gcd(b[i], b[i + 1]) != a[i]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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
