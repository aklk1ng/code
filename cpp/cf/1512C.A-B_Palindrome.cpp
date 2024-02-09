#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::string s;
  std::cin >> s;
  for (int _ = 0; _ < 2; _++) {
    for (int i = 0; i < (int)s.size(); i++) {
      int j = s.size() - i - 1;
      if (s[i] != '?') {
        if (s[j] == '?') {
          s[j] = s[i];
        } else if (s[i] != s[j]) {
          std::cout << -1 << '\n';
          return;
        }
      }
    }
    std::reverse(s.begin(), s.end());
  }
  a -= std::count(s.begin(), s.end(), '0');
  b -= std::count(s.begin(), s.end(), '1');
  int cnt = std::count(s.begin(), s.end(), '?');
  bool ok = (s.size() % 2 == 1 && s[s.size() / 2] == '?');
  if (a < 0 || b < 0 || a + b != cnt || (ok && a % 2 == 0 && b % 2 == 0)) {
    std::cout << "-1\n";
    return;
  }
  if (a % 2 == 1 || b % 2 == 1) {
    int i = s.size() / 2;
    if (s[i] != '?') {
      std::cout << "-1\n";
      return;
    }
    s[i] = a % 2 == 1 ? '0' : '1';
    if (a % 2 == 1) {
      a--;
    } else {
      b--;
    }
  }
  if (a % 2 == 1 || b % 2 == 1) {
    std::cout << "-1\n";
    return;
  }

  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '?') {
      int j = s.size() - i - 1;
      if (a > 0) {
        a -= 2;
        s[i] = s[j] = '0';
      } else {
        b -= 2;
        s[i] = s[j] = '1';
      }
    }
  }
  std::cout << s << '\n';
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
