#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::string S;
  std::cin >> S;

  std::string t = S.substr(3);
  int v = std::stoi(t);
  if (1 <= v && v <= 349 && v != 316) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
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
