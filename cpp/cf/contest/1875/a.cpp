#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, a, b;
  std::cin >> a >> b >> n;
  ll ans = b;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    ans += std::min(a - 1, x);
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
