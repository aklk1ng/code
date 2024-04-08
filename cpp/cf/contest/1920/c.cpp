#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int ans = 0;
  for (int k = 1; k <= n; k++) {
    if (n % k == 0) {
      int g = 0;
      for (int i = 0; i < n - k; i++) {
        g = std::__gcd(g, std::abs(a[i + k] - a[i]));
      }
      ans += (g != 1);
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
