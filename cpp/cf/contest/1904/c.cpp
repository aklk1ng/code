#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  if (k >= 3) {
    std::cout << "0\n";
    return;
  }
  std::sort(a.begin(), a.end());
  ll d = a[0];
  for (int i = 0; i < n - 1; i++) {
    d = std::min(d, a[i + 1] - a[i]);
  }
  if (k == 1) {
    std::cout << d << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      ll v = a[i] - a[j];
      int p = std::lower_bound(a.begin(), a.end(), v) - a.begin();
      if (p < n) {
        d = std::min(d, a[p] - v);
      }
      if (p > 0) {
        d = std::min(d, v - a[p - 1]);
      }
    }
  }
  std::cout << d << '\n';
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
