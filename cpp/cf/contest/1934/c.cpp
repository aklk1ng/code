#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;

  auto query = [&](int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) {
      return -1;
    }
    std::cout << "? " << x << ' ' << y << std::endl;
    int z;
    std::cin >> z;
    return z;
  };
  int d = query(1, 1);
  int lx = std::max(1, 2 + d - m);
  int p = query(lx, 2 + d - lx);
  int rx = std::max(1, 2 + d - n);
  int q = query(2 + d - rx, rx);
  if (query(lx + p / 2, 2 + d - lx - p / 2) == 0) {
    std::cout << "! " << lx + p / 2 << ' ' << 2 + d - lx - p / 2 << std::endl;
  } else {
    std::cout << "! " << 2 + d - rx - q / 2 << ' ' << rx + q / 2 << std::endl;
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
