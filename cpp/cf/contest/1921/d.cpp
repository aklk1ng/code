#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::sort(a.begin(), a.end());
  std::sort(b.rbegin(), b.rend());
  std::vector<int> c(n);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    c[i] = b[m - n + i];
    s += std::abs(c[i] - a[i]);
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = std::max(ans, s);
    if (i < n) {
      s -= std::abs(c[i] - a[i]);
      c[i] = b[i];
      s += std::abs(c[i] - a[i]);
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
