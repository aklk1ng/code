#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  int x = 1e9 + 7, pos = -1;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    if (a < x) {
      x = a;
      pos = i;
    }
  }
  std::cout << n - 1 << '\n';
  for (int i = 0; i < n; i++) {
    if (i == pos) {
      continue;
    }
    std::cout << pos + 1 << ' ' << i + 1 << ' ' << x << ' '
              << x + std::abs(i - pos) << '\n';
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
