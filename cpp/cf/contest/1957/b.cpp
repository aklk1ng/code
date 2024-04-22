#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  if (n == 1) {
    a[0] = k;
  } else {
    int msb = 0;
    for (int i = 0; i < 31; i++) {
      if (k & (1 << i)) {
        msb = i;
      }
    }
    a[0] = (1 << msb) - 1;
    a[1] = k - a[0];
    for (int i = 2; i < n; i++) {
      a[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i == n - 1];
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
