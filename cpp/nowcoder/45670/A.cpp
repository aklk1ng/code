// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

void solve() {
  int a, b, x;
  std::cin >> a >> b >> x;
  std::cout << (x - b) / a << std::endl;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
