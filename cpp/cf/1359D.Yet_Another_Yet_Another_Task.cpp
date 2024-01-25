#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll ans = 0;
  for (int i = 0; i < 31; i++) {
    ll cur = 0, best = 0;
    for (int j = 0; j < n; j++) {
      int val = a[j] > i ? -INF : a[j];
      cur += val;
      best = std::min(best, cur);
      ans = std::max(ans, (cur - best) - i);
    }
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
