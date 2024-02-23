#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m));
  std::vector aa(n + m, std::vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      aa[i + j].push_back(a[i][j]);
    }
  }
  std::vector b(n, std::vector<int>(m));
  std::vector bb(n + m, std::vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> b[i][j];
      bb[i + j].push_back(b[i][j]);
    }
  }

  bool ok = true;
  for (int i = 0; i < n + m; i++) {
    std::sort(aa[i].begin(), aa[i].end());
    std::sort(bb[i].begin(), bb[i].end());
    if (aa[i] != bb[i]) {
      ok = false;
    }
  }
  std::cout << (ok ? "YES" : "NO") << '\n';
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
