#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  int ans = 0;
  int n = s.size();
  for (int d = 1; d < n / 2 + 1; d++) {
    int cnt = 0;
    for (int i = 0; i < n - d; i++) {
      cnt += s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?';
      if (i - d >= 0) {
        cnt -= s[i] == s[i - d] || s[i] == '?' || s[i - d] == '?';
      }
      if (i - d >= -1 && cnt == d) {
        ans = 2 * d;
      }
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
