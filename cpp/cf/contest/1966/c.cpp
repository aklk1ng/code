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

  int mx = *std::max_element(a.begin(), a.end());
  std::sort(a.begin(), a.end());
  int mi = 1;
  for (auto &e : a) {
    if (e == mi) {
      mi++;
    }
  }
  if (mi > mx) {
    std::cout << (mx % 2 ? "Alice" : "Bob") << '\n';
  } else {
    std::cout << (mi % 2 ? "Alice" : "Bob") << '\n';
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
