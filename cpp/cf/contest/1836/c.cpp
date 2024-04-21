#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

int pow(int a, int e) {
  if (!e) {
    return 1;
  }
  return e == 1 ? a : a * pow(a, e - 1);
}

void solve() {
  int a, b, c;
  ll k;
  std::cin >> a >> b >> c >> k;

  for (int i = pow(10, a - 1); i < pow(10, a); i++) {
    int l = std::max(pow(10, b - 1), pow(10, c - 1) - i);
    int r = std::min(pow(10, b) - 1, pow(10, c) - 1 - i);
    if (l > r) {
      continue;
    }
    int len = r - l + 1;
    if (k <= len) {
      std::cout << i << " + " << l + k - 1 << " = " << i + l + k - 1 << '\n';
      return;
    }

    k -= len;
  }

  std::cout << "-1\n";
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
