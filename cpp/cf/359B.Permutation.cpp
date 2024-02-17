#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    if (k > 0) {
      std::cout << 2 * i + 2 << ' ' << 2 * i + 1 << ' ';
    } else {
      std::cout << 2 * i + 1 << ' ' << 2 * i + 2 << ' ';
    }
    k--;
  }
  std::cout << '\n';
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
