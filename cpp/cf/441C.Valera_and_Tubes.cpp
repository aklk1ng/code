#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  if (n == 3 && m == 3 && k == 3) {
    for (int i = 0; i < 3; i++) {
      std::cout << 3;
      for (int j = 0; j < 3; j++) {
        std::cout << ' ' << i + 1 << ' ' << j + 1;
      }
      std::cout << '\n';
    }
    return;
  }
  std::vector<std::pair<int, int>> path;
  int x = 0, y = 0, dir = 1;
  path.push_back({x + 1, y + 1});
  while (true) {
    y += dir;
    if (y == m) {
      dir *= -1;
      y = m - 1;
      x++;
    }
    if (y == -1) {
      dir *= -1;
      y = 0;
      x++;
    }
    if (x == n) {
      break;
    }
    path.push_back({x + 1, y + 1});
  }
  for (int i = 0; i < k - 1; i++) {
    std::cout << 2 << ' ' << path[2 * i].first << ' ' << path[2 * i].second
              << ' ' << path[2 * i + 1].first << ' ' << path[2 * i + 1].second
              << '\n';
  }
  std::cout << path.size() - 2 * (k - 1);
  for (int i = 2 * (k - 1); i < (int)path.size(); i++) {
    std::cout << ' ' << path[i].first << ' ' << path[i].second;
  }
  std::cout << '\n';
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
