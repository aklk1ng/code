// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  if ((c >= a && d >= b) || (c >= b && d >= a))
    std::cout << "YES";
  else
    std::cout << "NO";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
