#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int mi = *std::min_element(a.begin(), a.end());
  int cnt = 0;
  for (auto &e : a) {
    if (mi == e) {
      cnt++;
    }
    if ((mi & e) != mi) {
      std::cout << "0\n";
      return;
    }
  }

  int fac = 1;
  for (int i = 1; i <= n - 2; i++) {
    fac = (1LL * fac * i) % mod;
  }
  int ans = (1LL * cnt * (cnt - 1)) % mod;
  ans = (1LL * ans * fac) % mod;
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
