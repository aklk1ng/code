#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;

  if (n % 6 == 0) {
    std::cout << "YES\n";
    std::cout << "2 1 -1 ";
    for (int j = 0; j < n / 6 - 1; j++) {
      std::cout << "1 -1 -2 -1 1 2 ";
    }
    std::cout << "1 -1 -2\n";
  } else if (n % 6 == 1) {
    std::cout << "YES\n";
    std::cout << "-5 8 1 -3 -4 ";
    for (int j = 0; j < n / 6 - 1; j++) {
      std::cout << "-1 3 4 1 -3 -4 ";
    }
    std::cout << "-2 5\n";
  } else if (n % 6 == 2) {
    std::cout << "YES\n";
    for (int j = 0; j < n / 6; j++) {
      std::cout << "1 -1 -2 -1 1 2 ";
    }
    std::cout << "1 -1\n";
  } else if (n % 6 == 3) {
    if (n == 3) {
      std::cout << "NO\n";
      return;
    }
    std::cout << "YES\n";
    std::cout << "2 1 1 -3 -4 -1 3 ";
    for (int j = 0; j < n / 6 - 1; j++) {
      std::cout << "4 1 -3 -4 -1 3 ";
    }
    std::cout << "3 -2\n";
  } else if (n % 6 == 4) {
    std::cout << "YES\n";
    for (int j = 0; j < n / 6; j++) {
      std::cout << "1 -1 -2 -1 1 2 ";
    }
    std::cout << "1 -1 1 2\n";
  } else if (n % 6 == 5) {
    if (n == 5) {
      std::cout << "NO\n";
      return;
    }
    std::cout << "YES\n";
    std::cout << "-2 1 1 -3 -4 -1 3 ";
    for (int j = 0; j < n / 6 - 1; j++) {
      std::cout << "4 1 -3 -4 -1 3 ";
    }
    std::cout << "2 -1 2 4\n";
  }
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
