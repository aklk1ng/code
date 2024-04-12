#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;

  int ans = INT_MAX;
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 4; k++) {
        for (int t = 0; t <= 2; t++) {
          int sum = 1 * i + 3 * j + 6 * k + 10 * t;
          if (sum <= n && (n - sum) % 15 == 0) {
            ans = std::min(ans, i + j + k + t + (n - sum) / 15);
          }
        }
      }
    }
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
