#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  n = 2 * n + 1;
  char c = 0;
  while (n--) {
    std::string s;
    std::cin >> s;
    for (auto &e : s) {
      c ^= e;
    }
  }
  std::cout << c << '\n';
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
