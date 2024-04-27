#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  ll ans = 0;
  std::vector<ll> pr(n + 1);
  for (int i = 0; i < n; i++) {
    pr[i + 1] = pr[i] + a[i];
  }
  for (int i = 0; i <= k; i++) {
    ans = std::max(ans, pr[n - (k - i)] - pr[2 * i]);
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
