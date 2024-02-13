#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  std::vector<std::array<int, 4>> ans;
  if (a[0][0] == 1) {
    std::cout << "-1\n";
    return;
  }

  for (int j = m - 1; j >= 0; j--) {
    for (int i = n - 1; i >= 0; i--) {
      if (a[i][j]) {
        if (i) {
          ans.push_back({i, j + 1, i + 1, j + 1});
        } else {
          ans.push_back({i + 1, j, i + 1, j + 1});
        }
      }
    }
  }

  std::cout << ans.size() << '\n';
  for (auto &e : ans) {
    std::cout << e[0] << ' ' << e[1] << ' ' << e[2] << ' ' << e[3] << '\n';
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
