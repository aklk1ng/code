// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = n; i >= 1; i -= 2) {
    ans += a[i];
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  solve();

  return 0;
}
