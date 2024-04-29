#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int l = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[l];
    l++;
    while (l > 1) {
      if (a[l - 2] == a[l - 1]) {
        a[l - 2]++;
        l--;
      } else {
        break;
      }
    }
  }
  std::cout << l << '\n';
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
