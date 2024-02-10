#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }

  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] * a[i][j + 1] * a[i + 1][j] * a[i + 1][j + 1] > 0) {
        a[i][j] = 2;
        a[i + 1][j] = 2;
        a[i][j + 1] = 2;
        a[i + 1][j + 1] = 2;
        ans.push_back({i, j});
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += std::count(a[i].begin(), a[i].end(), 1);
  }
  if (cnt) {
    std::cout << "-1\n";
  } else {
    std::cout << ans.size() << '\n';
    for (auto &e : ans) {
      std::cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
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
