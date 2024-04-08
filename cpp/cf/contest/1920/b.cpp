#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k, x;
  std::cin >> n >> k >> x;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin() + 1, a.end(), std::greater<int>());
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  int ans = -1e9;
  for (int i = 0; i <= k; i++) {
    ans = std::max(ans, a[n] - 2 * a[std::min(i + x, n)] + a[i]);
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
