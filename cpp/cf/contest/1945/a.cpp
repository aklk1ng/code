#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  int t = (3 - b % 3) % 3;
  if (b > 0 && t > c) {
    std::cout << "-1\n";
    return;
  }

  c -= t;
  b += t;
  std::cout << a + c / 3 + (c % 3 + 1) / 2 + b / 3 << '\n';
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
