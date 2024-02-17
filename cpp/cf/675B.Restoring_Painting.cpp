#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, a, b, c, d;
  std::cin >> n >> a >> b >> c >> d;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int y = i + b - c;
    int z = i + a - d;
    int w = a + y - d;
    if (1 <= y && y <= n && 1 <= z && z <= n && 1 <= w && w <= n) {
      ans++;
    }
  }
  ans *= n;
  std::cout << ans << '\n';
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
