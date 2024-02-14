#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  ll m;
  std::cin >> n >> m;
  ll cur = 1, rem = m;
  while (rem > 0) {
    ll d = std::min(cur, rem);
    rem -= d;
    cur++;
  }
  ll ans = n;
  if (cur > 1) {
    ans = n - cur;
  }
  std::cout << std::max(0LL, n - m * 2) << ' ' << ans << '\n';
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
