#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  bool ok = false;
  for (int i = 1; i <= n - 1; i++) {
    if (std::abs(a[i + 1] - a[i]) > 1) {
      std::cout << "YES\n";
      std::cout << i << ' ' << i + 1 << '\n';
      ok = true;
      break;
    }
  }
  if (!ok) {
    std::cout << "NO\n";
  }
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
