#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  if (a[n - 2] > a[n - 1]) {
    std::cout << "-1\n";
  } else {
    if (a[n - 1] < 0) {
      if (std::is_sorted(a.begin(), a.end())) {
        std::cout << "0\n";
      } else {
        std::cout << "-1\n";
      }
    } else {
      std::cout << n - 2 << '\n';
      for (int i = 1; i <= n - 2; i++) {
        std::cout << i << ' ' << n - 1 << ' ' << n << '\n';
      }
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
