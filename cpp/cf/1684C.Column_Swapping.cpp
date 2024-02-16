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

  std::vector<int> bad;
  for (int i = 0; i < n && bad.empty(); i++) {
    std::vector<int> b = a[i];
    std::sort(b.begin(), b.end());
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[j]) {
        bad.push_back(j);
      }
    }
  }
  if (bad.empty()) {
    std::cout << "1 1\n";
    return;
  }
  if ((int)bad.size() > 2) {
    std::cout << "-1\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    std::swap(a[i][bad[0]], a[i][bad[1]]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] < a[i][j - 1]) {
        std::cout << "-1\n";
        return;
      }
    }
  }
  std::cout << bad[0] + 1 << ' ' << bad[1] + 1 << '\n';
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
