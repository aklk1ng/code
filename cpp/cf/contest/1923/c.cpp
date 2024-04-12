#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> c(n), cnt(n + 1);
  std::vector<ll> sum(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
    sum[i + 1] = sum[i] + c[i];
    cnt[i + 1] = cnt[i] + (c[i] == 1);
  }

  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    int cur = cnt[r] - cnt[l];
    ll tot = sum[r] - sum[l];
    if ((r - l) + cur <= tot && r - l > 1) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
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
