#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  if (n % 2) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (j - i <= n / 2) {
          std::cout << "1 ";
        } else {
          std::cout << "-1 ";
        }
      }
    }
    std::cout << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (j - i < n / 2) {
          std::cout << "1 ";
        } else if (j - i == n / 2) {
          std::cout << "0 ";
        } else {
          std::cout << "-1 ";
        }
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
