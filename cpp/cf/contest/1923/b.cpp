#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), x(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }

  std::vector<ll> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[std::abs(x[i])] += a[i];
  }
  bool ok = true;
  ll lf = 0;
  for (int i = 1; i <= n; i++) {
    lf += k - s[i];
    ok &= lf >= 0;
  }
  std::cout << (ok ? "YES" : "NO") << '\n';
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
