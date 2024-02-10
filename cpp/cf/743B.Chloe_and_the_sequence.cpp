#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  ll k;
  std::cin >> n >> k;
  auto cal = [&](auto self, ll l, ll r, ll need, int num) -> int {
    ll m = l + (r - l) / 2;
    if (need < m) {
      return self(self, l, m - 1, need, num - 1);
    } else if (need > m) {
      return self(self, m + 1, r, need, num - 1);
    } else {
      return num;
    }
  };
  ll sz = 1;
  for (int i = 1; i < n; i++) {
    sz = sz * 2LL + 1LL;
  }
  std::cout << cal(cal, 1, sz, k, n);
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
