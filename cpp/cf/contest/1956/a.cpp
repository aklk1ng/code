#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int q, k;
  std::cin >> k >> q;
  std::vector<int> a(k);
  for (int i = 0; i < k; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    int n;
    std::cin >> n;
    std::cout << std::min(a[0] - 1, n) << " \n"[i == q - 1];
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
