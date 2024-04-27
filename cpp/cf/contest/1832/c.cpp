#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  n = std::unique(a.begin(), a.end()) - a.begin();
  int ans = n;
  for (int i = 0; i + 2 < n; i++) {
    ans -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
    ans -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
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
