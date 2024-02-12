#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, p;
  std::cin >> n >> p;
  std::string s;
  std::cin >> s;
  std::string t = s;
  auto check = [&]() {
    for (int i = p; i < n; i++) {
      if (t[i] != t[i - p]) {
        return false;
      }
    }
    return true;
  };

  for (auto &e : t) {
    if (e == '.') {
      e = '0';
    }
  }
  if (!check()) {
    std::cout << t << '\n';
    return;
  }
  int i = 0;
  while (i < n && s[i] != '.') {
    i++;
  }
  if (i + p < n) {
    t[i] = '1';
    std::cout << t << '\n';
    return;
  }
  i = n - 1;
  while (i >= 0 && s[i] != '.') {
    i--;
  }
  if (i - p >= 0) {
    t[i] = '1';
    std::cout << t << '\n';
    return;
  }
  std::cout << "NO\n";
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
