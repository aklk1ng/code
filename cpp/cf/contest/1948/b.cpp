#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> b({a[n - 1]});
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > b.back()) {
      b.push_back(a[i] % 10);
      b.push_back(a[i] / 10);
    } else {
      b.push_back(a[i]);
    }
  }
  std::cout << (std::is_sorted(b.rbegin(), b.rend()) ? "YES" : "NO") << '\n';
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
