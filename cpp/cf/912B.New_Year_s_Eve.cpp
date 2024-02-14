#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  ll n, k;
  std::cin >> n >> k;
  if (k == 1) {
    std::cout << n << '\n';
    return;
  }

  ll ans = 1;
  while (ans < n) {
    ans = ans * 2 + 1;
  }
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
