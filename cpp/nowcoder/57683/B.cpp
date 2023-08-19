// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int t, n;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cout << n << " " << 2 * n << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
