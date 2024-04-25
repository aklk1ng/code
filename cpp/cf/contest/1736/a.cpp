#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  int sum = 0, ans = 0;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++){
    std::cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++){
    std::cin >> b[i];
    sum -= b[i];
  }

  for (int i = 0; i < n; i++) {
    ans += (a[i] ^ b[i]);
  }
  std::cout << std::min(ans, 1 + std::abs(sum)) << '\n';
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
