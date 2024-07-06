#include <bits/stdc++.h>
typedef long long ll;
const int INF = 2e9 + 7;

void solve() {
  int m;
  std::cin >> m;
  std::vector a(2, std::vector<int>(m));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector su(2, std::vector<int>(m + 1, -INF));
  for (int i = 0; i < 2; i++) {
    for (int j = m - 1; j >= 0; j--) {
      su[i][j] = std::max(
          {su[i][j + 1] - 1, a[i][j], a[i ^ 1][j] - (2 * (m - j) - 1)});
    }
  }

  int pr = a[0][0] - 1;
  int ans = INF;
  for (int j = 0; j < m; j++) {
    int jj = j & 1;
    ans = std::min({ans, std::max({pr, su[jj][j + 1] - 2 * j - 1,
                                   a[jj ^ 1][j] - 2 * m + 1})});
    pr = std::max(pr, a[jj ^ 1][j] - 2 * j - 1);
    ans = std::min(ans, std::max(pr, su[jj ^ 1][j + 1] - 2 * j - 2));
    if (j < m - 1) {
      pr = std::max(pr, a[jj ^ 1][j + 1] - 2 * j - 2);
    }
  }

  std::cout << ans + 2 * m << '\n';
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
