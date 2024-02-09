#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int q;
  std::cin >> q;
  while (q--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      cnt += a[i] % 2;
    }
    if (cnt < k || cnt % 2 != k % 2) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (k == 1) {
        break;
      }
      if (a[i] % 2) {
        std::cout << i + 1 << ' ';
        k--;
      }
    }
    std::cout << n << '\n';
  }
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
