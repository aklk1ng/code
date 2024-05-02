#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  int ans = 1;
  if (s[0] == '0') {
    ans = 0;
  }
  if (s[0] == '?') {
    ans = 9;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '?') {
      ans *= 10;
    }
  }
  std::cout << ans << '\n';
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
