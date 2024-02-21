#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  if (n == 1) {
    std::cout << "-1\n";
  } else {
    std::cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << '\n';
  }
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
