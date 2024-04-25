#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int freq = 0, need = 0;
  std::vector<int> ans;
  for (int i = 0; i < 2 * n; i += 2) {
    if (s[i] != s[i + 1]) {
      freq++;
      ans.push_back(i + 1);
      if (s[i] - '0' != need) {
        ans.back()++;
      }
      need ^= 1;
    }
  }
  if (freq & 1) {
    std::cout << "-1\n";
    return;
  }
  std::cout << ans.size() << '\n';
  for (auto &e : ans) {
    std::cout << e << " \n"[e == ans.back()];
  }
  for (int i = 1; i <= 2 * n; i += 2) {
    std::cout << i << " \n"[i + 1 == 2 * n];
  }
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
