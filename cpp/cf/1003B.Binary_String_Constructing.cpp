#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b, x;
  std::cin >> a >> b >> x;
  if (x % 2 == 0) {
    if (a > b) {
      for (int i = 0; i < x / 2; i++) {
        std::cout << "01";
      }
      std::cout << std::string(b - x / 2, '1');
      std::cout << std::string(a - x / 2, '0');
    } else {
      for (int i = 0; i < x / 2; i++) {
        std::cout << "10";
      }
      std::cout << std::string(a - x / 2, '0');
      std::cout << std::string(b - x / 2, '1');
    }
  } else if (a > b) {
    for (int i = 0; i < x / 2; i++) {
      std::cout << "01";
    }
    std::cout << std::string(a - x / 2, '0');
    std::cout << std::string(b - x / 2, '1');
  } else {
    for (int i = 0; i < x / 2; i++) {
      std::cout << "10";
    }
    std::cout << std::string(b - x / 2, '1');
    std::cout << std::string(a - x / 2, '0');
  }
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
