#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "1\n";
    return;
  }
  if (n % 2) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        std::cout << i << ' ';
      } else {
        std::cout << n - i << ' ';
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
