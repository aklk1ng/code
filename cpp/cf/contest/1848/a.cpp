#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int x, y;
  std::cin >> x >> y;
  std::string ans = "YES\n";
  while (k--) {
    int xx, yy;
    std::cin >> xx >> yy;
    if ((x + y) % 2 == (xx + yy) % 2) {
      ans = "NO\n";
    }
  }
  std::cout << ans;
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
