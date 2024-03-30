#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a + 1 != c) {
    std::cout << "-1\n";
    return;
  }
  if (a + b + c == 1) {
    std::cout << "0\n";
    return;
  }

  int cur = 1, next = 0, ans = 1;
  for (int i = 0; i < a + b; i++) {
    if (!cur) {
      std::swap(next, cur);
      ans++;
    }
    cur--;
    next++;
    if (i < a) {
      next++;
    }
  }
  std::cout << ans << '\n';
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
