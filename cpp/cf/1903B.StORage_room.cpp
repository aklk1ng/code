#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, (1 << 30) - 1);
  std::vector m(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> m[i][j];
      if (i != j) {
        a[i] &= m[i][j];
        a[j] &= m[i][j];
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && (a[i] | a[j]) != m[i][j]) {
        ok = false;
      }
    }
  }
  if (!ok) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
      std::cout << a[i] << " \n"[i == n - 1];
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
