#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string s;
  std::cin >> s;

  int n = s.size();
  int ans = n;
  for (int i = 0; i < 26; i++) {
    int c = char(i + 'a');
    int j = 0, cur = 0;
    while (j < n) {
      int k = j;
      while (k < n && (s[k] == c) == (s[j] == c)) {
        k++;
      }
      if (s[j] != c) {
        cur = std::max(cur, k - j);
      }
      j = k;
    }
    if (!cur) {
      ans = 0;
      break;
    }
    int p = 0;
    while ((1 << p) <= cur) {
      p++;
    }
    ans = std::min(ans, p);
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
