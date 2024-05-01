#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i % 2) {
      sum += a[i];
    } else {
      sum -= a[i];
    }
  }
  if (n % 2 || sum >= 0) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
