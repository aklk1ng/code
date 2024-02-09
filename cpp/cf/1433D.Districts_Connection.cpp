#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &e : a) {
    std::cin >> e;
  }

  std::vector<std::pair<int, int>> res;
  int idx = -1;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[0]) {
      idx = i;
      res.push_back({1, i + 1});
    }
  }
  if (idx == -1) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] == a[0]) {
      res.push_back({idx + 1, i + 1});
    }
  }
  std::cout << "YES\n";
  for (auto &[x, y] : res) {
    std::cout << x << ' ' << y << '\n';
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
