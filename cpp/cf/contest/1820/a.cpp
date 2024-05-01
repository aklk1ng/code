#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  if (s == "^") {
    std::cout << "1\n";
    return;
  }
  int ans = 0;
  if (s[0] == '_') {
    ans++;
  }
  if (s.back() == '_') {
    ans++;
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == '_' && s[i + 1] == '_') {
      ans++;
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
