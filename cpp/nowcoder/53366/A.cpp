// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl

void solve() {
  std::string s;
  std::cin >> s;
  for (auto c : s) {
    if (std::islower(c))
      std::cout << (char)std::toupper(c);
    else
      std::cout << (char)std::tolower(c);
  }
  std::cout << std::endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();
  return 0;
}
