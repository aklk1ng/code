#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  ll ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += std::abs(a[i] - a[i - 1]);
  }
  int mx = std::max(std::abs(a[1] - a[2]), std::abs(a[n] - a[n - 1]));
  for (int i = 2; i < n; i++) {
    mx = std::max(mx, std::abs(a[i] - a[i - 1]) + std::abs(a[i + 1] - a[i]) -
                          std::abs(a[i + 1] - a[i - 1]));
  }
  std::cout << ans - mx << '\n';
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
