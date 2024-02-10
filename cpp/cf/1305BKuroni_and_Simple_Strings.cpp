#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  std::string s;
  std::cin >> s;
  std::vector<int> lf, rg;
  int n = s.size();
  int l = 0, r = n - 1;
  while (l < r) {
    while (l < n && s[l] == ')') {
      l++;
    }
    while (r >= 0 && s[r] == '(') {
      r--;
    }
    if (l < n && r >= 0 && l < r) {
      lf.push_back(l + 1);
      rg.push_back(r + 1);
      l++;
      r--;
    }
  }
  if (lf.empty()) {
    std::cout << "0\n";
    return;
  }
  std::cout << "1\n" << 2 * lf.size() << '\n';
  for (auto &e : lf) {
    std::cout << e << ' ';
  }
  std::reverse(rg.begin(), rg.end());
  for (auto &e : rg) {
    std::cout << e << " \n"[e == rg.back()];
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
