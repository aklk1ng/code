#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  k--;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  int x = 0, y = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[x]) {
      x = i;
    }
  }
  for (int i = 1; i < m; i++) {
    if (b[i] > b[y]) {
      y = i;
    }
  }
  if (b[y] > a[x]) {
    std::swap(a[x], b[y]);
  }
  if (k & 1) {
    x = 0, y = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[x]) {
        x = i;
      }
    }
    for (int i = 1; i < m; i++) {
      if (b[i] < b[y]) {
        y = i;
      }
    }
    std::swap(a[x], b[y]);
  }

  std::cout << std::accumulate(a.begin(), a.end(), 0LL) << '\n';
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
