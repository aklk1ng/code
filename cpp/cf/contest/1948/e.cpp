#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n), c(n);
  std::iota(a.begin(), a.end(), 1);
  for (int i = 0; i < n; i++) {
    c[i] = i / k + 1;
  }
  int q = *std::max_element(c.begin(), c.end());
  for (int i = 1; i <= q; i++) {
    int l = std::find(c.begin(), c.end(), i) - c.begin();
    int r = c.rend() - std::find(c.rbegin(), c.rend(), i);
    int m = (l + r) / 2;
    std::reverse(a.begin() + l, a.begin() + m);
    std::reverse(a.begin() + m, a.begin() + r);
  }

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
  }
  std::cout << q << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << c[i] << " \n"[i == n - 1];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
