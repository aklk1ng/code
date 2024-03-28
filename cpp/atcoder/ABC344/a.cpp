#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string s;
  std::cin >> s;

  int l = s.find('|');
  int r = s.rfind('|');
  std::cout << s.substr(0, l) + s.substr(r + 1) << '\n';
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
