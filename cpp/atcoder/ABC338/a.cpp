#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  std::string s;
  std::cin >> s;
  int cnt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (std::isupper(s[i])) {
      cnt++;
    }
  }
  std::cout << (cnt == 1 && std::isupper(s[0]) ? "Yes" : "No") << '\n';
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
