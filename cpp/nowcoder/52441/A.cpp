// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  ll a, b;
  std::cin >> a >> b;
  int oth = a / b;
  int res = a % b;
  if (res > oth)
    std::cout << "niuniu eats more than others"
              << "\n";
  else if (res < oth)
    std::cout << "niuniu eats less than others"
              << "\n";
  else
    std::cout << "same"
              << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
