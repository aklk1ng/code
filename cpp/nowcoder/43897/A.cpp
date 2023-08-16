// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  int sum = 0;
  while (n--) {
    int tmp;
    std::cin >> tmp;
    sum += tmp;
  }
  std::cout << sum * 2;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
