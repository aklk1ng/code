#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 == 0) {
        std::cout << (n / 2 + i / 2) * m + j + 1 << ' ';
      } else {
        std::cout << (i / 2) * m + j + 1 << ' ';
      }
    }
    std::cout << '\n';
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
