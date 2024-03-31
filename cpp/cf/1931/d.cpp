#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::map<std::pair<int, int>, int> m;
  ll ans = 0;
  for (auto &e : a) {
    int xx = e % x, yy = e % y;
    if (m.count({(x - xx) % x, yy})) {
      ans += m[{(x - xx) % x, yy}];
    }
    m[{xx, yy}]++;
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
