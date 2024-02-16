#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> mi(n + 1, n);
  mi[0] = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x > y) {
      std::swap(x, y);
    }
    mi[x] = std::min(mi[x], y - 1);
  }

  for (int i = n - 1; i > 0; i--) {
    mi[i] = std::min(mi[i], mi[i + 1]);
  }
  ll ans = n;
  for (int i = 0; i < n; i++) {
    ans += mi[i] - i;
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
