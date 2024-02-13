#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    bool found = false;
    for (int j = i + 1; j >= 2; j--) {
      if (x % j) {
        found = true;
        break;
      }
    }
    ok &= found;
  }
  std::cout << (ok ? "YES" : "NO") << '\n';
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
