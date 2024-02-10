#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if ((n - 1LL) * n >> 1 < m || m < n - 1) {
    std::cout << "NO\n";
    return;
  }
  if (n == 1) {
    if (k > 1) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  } else if (m < (n - 1LL) * n >> 1) {
    if (k > 3) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  } else if (k > 2) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
