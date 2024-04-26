#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::sort(b.begin(), b.end(), std::greater<>());

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    int t = a.size() - (std::upper_bound(a.begin(), a.end(), b[i]) - a.begin());
    ans = ans * std::max(t - i, 0) % mod;
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
