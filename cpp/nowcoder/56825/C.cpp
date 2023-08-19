// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  int a[n], b[n];
  ll suma = 0, sumb = 0, sums = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    suma += a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    sumb += b[i];
  }
  for (int i = 0; i < n; i++) {
    sums += abs(a[i] - b[i]);
  }
  if (suma != sumb)
    std::cout << "-1";
  else
    std::cout << (sums + 1) / 2;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
