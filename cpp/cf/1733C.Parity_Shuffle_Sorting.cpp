#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::cout << n - 1 << '\n';
  if (n > 1) {
    std::cout << 1 << ' ' << n << '\n';
  }
  int x = (a[1] + a[n]) % 2 ? a[1] : a[n];
  for (int i = 2; i < n; i++) {
    if ((x + a[i]) % 2) {
      std::cout << 1 << ' ' << i << '\n';
    } else {
      std::cout << i << ' ' << n << '\n';
    }
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
