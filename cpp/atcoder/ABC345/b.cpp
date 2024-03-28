#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  ll x;
  std::cin >> x;
  if ((x + 9) < 0 && (x + 9) % 10 != 0) {
    std::cout << (x + 9) / 10 - 1 << '\n';
  } else {
    std::cout << (x + 9) / 10 << '\n';
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
