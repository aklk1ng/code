#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<ll> s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    s[i] += s[i - 1];
  }

  if (k >= n) {
    std::cout << s[n] + (k - 1LL + k - n) * n / 2 << '\n';
  } else {
    ll mx = s[k];
    for (int i = k + 1; i <= n; i++) {
      mx = std::max(mx, s[i] - s[i - k]);
    }
    std::cout << mx + k * (k - 1LL) / 2 << '\n';
  }
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
