#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  auto cal = [&]() {
    std::vector<ll> d1(n + 1), d2(n + 2);
    d1[0] = -static_cast<ll>(1e18);
    d2[0] = 0;
    for (int i = 0; i < n; i++) {
      d1[i + 1] = std::max(d1[i], d2[i] + a[i]);
      d2[i + 1] = std::max(d2[i], d1[i] - a[i]);
    }
    return std::max(d1.back(), d2.back());
  };
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << cal() << '\n';

  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    std::cout << cal() << '\n';
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
