#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }

  int ans = n;
  std::map<int, int> s;
  for (auto &e : c) {
    if (s.count(e)) {
      s[e]++;
    } else {
      s[e] = 1;
    }
    if (s[e] >= k) {
      ans = k - 1;
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
