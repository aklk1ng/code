#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int diff = 1e9;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i > 0) {
      diff = std::min(diff, a[i] - a[i - 1]);
      ok &= a[i] >= a[i - 1];
    }
  }

  std::cout << (ok ? diff / 2 + 1 : 0) << '\n';
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
