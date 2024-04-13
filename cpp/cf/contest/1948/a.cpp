#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;

  if (n % 2 == 1) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << "AB"[i & 1];
    }
  }
  std::cout << '\n';
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
