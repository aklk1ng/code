#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::string s;
  std::cin >> s;
  a--, b--;
  std::cout << ((s[a] - '0') ^ (s[b] - '0'));
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
