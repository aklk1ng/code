#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b;
  std::cin >> a >> b;
  for (int i = 0; i < 10; i++) {
    if (i != a + b) {
      std::cout << i << '\n';
      return;
    }
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
