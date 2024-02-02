#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  std::string s;
  std::cin >> s;
  std::map<char, int> m;
  for (auto c : s) {
    m[c]++;
  }
  char ans = 'a';
  for (char c = 'a'; c <= 'z'; c++) {
    if (m[c] > m[ans]) {
      ans = c;
    }
  }
  std::cout << ans << '\n';
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
