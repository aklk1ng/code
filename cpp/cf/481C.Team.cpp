#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  int t = 0, k = 0;
  std::vector<int> a(m + 2);
  if (n - 1 <= m && m <= 2 * (n + 1)) {
    if (m == n - 1) {
      a[0] = -1;
      a[m + 1] = -1;
      t = n - 1;
    } else if (m == n) {
      a[m + 1] = -1;
      t = n;
    } else {
      t = n + 1;
    }
    k = m % t;
    if (k == 0 && m != t) {
      k = n + 1;
    }
    if (a[0] == -1) {
      std::cout << 0;
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] != -1) {
        if (k > 0) {
          std::cout << "110";
        } else {
          std::cout << "10";
        }
        k--;
      }
    }
    if (a[m + 1] != -1) {
      if (k > 0) {
        std::cout << "11\n";
      } else {
        std::cout << "1\n";
      }
    }
  } else {
    std::cout << "-1\n";
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
