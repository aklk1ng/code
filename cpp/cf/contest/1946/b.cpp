#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll mx = 0, sum = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    cur += a[i];
    cur = std::max(cur, 0LL);
    mx = std::max(mx, cur);
  }
  sum = (sum % mod + mod) % mod;
  mx = mx % mod;
  int t = 1;
  for (int i = 0; i < k; i++) {
    t = t * 2 % mod;
  }
  std::cout << (sum + mx * t - mx + mod) % mod << '\n';;
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
