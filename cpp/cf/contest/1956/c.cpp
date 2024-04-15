#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (2 * i - 1) * i;
  }
  std::cout << ans << ' ' << 2 * n << '\n';
  for (int i = n; i >= 1; i--) {
    std::cout << "1 " << i << ' ';
    for (int j = 1; j <= n; j++) {
      std::cout << j << " \n"[j == n];
    }
    std::cout << "2 " << i << ' ';
    for (int j = 1; j <= n; j++) {
      std::cout << j << " \n"[j == n];
    }
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
