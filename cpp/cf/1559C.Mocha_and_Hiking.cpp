#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  if (a[1]) {
    std::cout << n + 1 << ' ';
    for (int i = 1; i <= n; i++) {
      std::cout << i << " \n"[i == n];
    }
    return;
  }
  for (int i = 1; i < n; i++) {
    if (!a[i] && a[i + 1]) {
      for (int j = 1; j <= i; j++) {
        std::cout << j << ' ';
      }
      std::cout << n + 1 << ' ';
      for (int j = i + 1; j <= n; j++) {
        std::cout << j << " \n"[j == n];
      }
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << i << ' ';
  }
  std::cout << n + 1 << '\n';
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
