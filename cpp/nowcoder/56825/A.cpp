// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  bool flag = true;
  if (a[0] >= a[n - 1])
    std::cout << "NO"
              << "\n";
  else
    std::cout << "YES"
              << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
