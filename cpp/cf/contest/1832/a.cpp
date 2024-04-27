#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  s = s.substr(0, s.size() / 2);
  std::cout << (std::unique(s.begin(), s.end()) - s.begin() == 1 ? "NO" : "YES")
            << '\n';
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
