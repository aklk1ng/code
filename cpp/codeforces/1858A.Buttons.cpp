// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a > b)
    std::cout << "First" << std::endl;
  else if (a < b)
    std::cout << "Second" << std::endl;
  else {
    if (c % 2)
      std::cout << "First" << std::endl;
    else
      std::cout << "Second" << std::endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
