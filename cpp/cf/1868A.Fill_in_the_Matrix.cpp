#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  if (m == 1) {
    std::cout << 0 << '\n';
  } else if (n > m - 1) {
    std::cout << m << '\n';
  } else {
    std::cout << n + 1 << '\n';
  }
  for (int i = 0; i < std::min(m - 1, n); i++) {
    for (int j = 0; j < m; j++) {
      std::cout << (j + i) % m << " \n"[j == m - 1];
    }
  }
  if (n > m - 1) {
    for (int i = m - 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << j << " \n"[j == m - 1];
      }
    }
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
