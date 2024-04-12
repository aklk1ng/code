#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }

  int odd = 0, even = 0;
  ll ans = 1LL * (c + 1) * (c + 2) / 2;
  for (int i = 0; i < n; i++) {
    ans -= s[i] / 2 + 1;
    ans -= c - s[i] + 1;
    if (s[i] % 2) {
      odd++;
    } else {
      even++;
    }
  }
  ans += 1LL * even * (even + 1) / 2;
  ans += 1LL * odd * (odd + 1) / 2;
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
