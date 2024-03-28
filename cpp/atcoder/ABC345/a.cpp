#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string s;
  std::cin >> s;
  if (*s.begin() == '<' && *s.rbegin() == '>' &&
      std::count(s.begin() + 1, s.end() - 1, '=') == (int)s.size() - 2) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
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
