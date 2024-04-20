#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int N;
  std::cin >> N;

  std::string s;
  for (int i = 1; i <= N; i++) {
    if (i % 3 == 0) {
      s += 'x';
    } else {
      s += 'o';
      }
  }
  std::cout << s << '\n';
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
