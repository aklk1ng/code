#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < 2 * n; j++) {
      std::cout << ((i / 2 + j / 2 & 1) ? '.' : '#');
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
