#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string s;
  std::cin >> s;

  std::map<char, int> m;
  for (auto &e : s) {
    m[e]++;
  }

  for (auto &[k, v] : m) {
    if (v == 1) {
      std::cout << s.find(k) + 1 << '\n';
      return;
    }
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
