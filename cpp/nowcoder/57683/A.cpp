// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = n;; i++) {
    if (i % 3 == 0) {
      std::cout << i << '\n';
      break;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
