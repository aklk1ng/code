#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  ll sum = 0, x = 0;
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    sum += t;
    x ^= t;
  }
  std::cout << 2 << '\n' << x << ' ' << x + sum << '\n';
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
