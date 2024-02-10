#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int k;
  std::cin >> k;
  if (k > 36) {
    std::cout << "-1\n";
  } else {
    while (k > 0) {
      if (k >= 2) {
        std::cout << 8;
        k -= 2;
      } else {
        std::cout << 9;
        k--;
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
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
