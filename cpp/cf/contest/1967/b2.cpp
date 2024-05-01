#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;

  int sq = sqrt(n) + 2, sqm = sqrt(m) + 2;
  std::vector bad(sq + 1, std::vector<bool>(sqm + 1));
  for (int i = 2; i <= std::min(sq, sqm); i++) {
    for (int a = i; a <= sq; a += i) {
      for (int b = i; b <= sqm; b += i) {
        bad[a][b] = true;
      }
    }
  }
  ll ans = 0;
  for (int a = 1; a * a <= n; a++) {
    for (int b = 1; b * b <= m; b++) {
      if (bad[a][b]) {
        continue;
      }
      ans += std::min(n / (a + b) / a, m / (a + b) / b);
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
