#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  ll n, x, y;
  std::cin >> n >> x >> y;
  std::string a, b;
  std::cin >> a >> b;

  ll d = 0;
  for (int i = 0; i < n; i++) {
    a[i] ^= b[i];
    d += a[i];
  }

  if (d % 2) {
    std::cout << "-1\n";
    return;
  }
  if (d == 2) {
    int l = 0, r = n - 1;
    while (!a[l]) {
      l++;
    }
    while (!a[r]) {
      r--;
    }
    if (l + 1 == r) {
      std::cout << std::min(x, 2 * y) << '\n';
    } else {
      std::cout << std::min((r - 1) * x, y) << '\n';
    }
  } else {
    std::cout << d / 2 * y << '\n';
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
