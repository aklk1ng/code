#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector<int> ord(n);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] > b[j]; });
  ll f = 0, p = 0;
  for (auto &e : ord) {
    p += std::max(0, b[e] - a[e]);
  }
  ll ans = 0;
  std::multiset<int> s;
  if (s.size() == k) {
    ans = std::max(ans, p - f);
  }
  for (auto &e : ord) {
    p -= std::max(0, b[e] - a[e]);
    s.insert(a[e]);
    f += a[e];
    if (s.size() > k) {
      f -= *s.rbegin();
      s.erase(--s.end());
    }
    if (s.size() == k) {
      ans = std::max(ans, p - f);
    }
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
