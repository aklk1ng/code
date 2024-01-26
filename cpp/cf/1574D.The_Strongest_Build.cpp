#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a, b;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    int c;
    std::cin >> c;
    a[i].resize(c);
    for (int j = 0; j < c; j++) {
      std::cin >> a[i][j];
    }
  }
  int m;
  std::cin >> m;
  b.resize(m);
  for (int i = 0; i < m; i++) {
    b[i].resize(n);
    for (int j = 0; j < n; j++) {
      std::cin >> b[i][j];
      b[i][j]--;
    }
  }
  std::sort(b.begin(), b.end());
  std::vector<int> u(n);
  for (int i = 0; i < n; i++) {
    u[i] = (int)a[i].size() - 1;
  }
  if (!std::binary_search(b.begin(), b.end(), u)) {
    for (int i = 0; i < n; i++) {
      std::cout << u[i] + 1 << " \n"[i == n - 1];
    }
    return;
  }

  int mx = 0;
  std::vector<int> ans(n, -1);
  for (int i = 0; i < m; i++) {
    std::vector<int> t = b[i];
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += a[j][t[j]];
    }
    for (int j = 0; j < n; j++) {
      if (t[j]) {
        t[j]--;
        if (!std::binary_search(b.begin(), b.end(), t) &&
            sum - a[j][t[j] + 1] + a[j][t[j]] > mx) {
          mx = sum - a[j][t[j] + 1] + a[j][t[j]];
          ans = t;
        }
        t[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] + 1 << " \n"[i == n - 1];
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
