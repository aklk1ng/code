#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
  }

  int ans = 3;
  for (int i = 0; i < n; i++) {
    if (p[p[i]] == i) {
      ans = 2;
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
