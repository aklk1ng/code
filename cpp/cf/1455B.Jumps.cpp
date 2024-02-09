#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int x;
  std::cin >> x;
  int cnt = 0;
  while (cnt * (cnt + 1) < 2 * x) {
    cnt++;
  }
  if (cnt * (cnt + 1) / 2 == x + 1) {
    cnt++;
  }
  std::cout << cnt << '\n';
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
