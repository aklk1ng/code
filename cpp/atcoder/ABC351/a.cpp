#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  std::vector<int> a(9), b(8);
  for (int i = 0; i < 9; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < 8; i++) {
    std::cin >> b[i];
  }

  std::cout << (std::accumulate(a.begin(), a.end(), 0) -
                std::accumulate(b.begin(), b.end(), 0) + 1)
            << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
