#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  int l = 1, r = 1e9, s = 0;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int a, x;
    std::cin >> a >> x;
    if (a == 1) {
      l = std::max(l, x);
    }
    if (a == 2) {
      r = std::min(r, x);
    }
    if (a == 3) {
      v.push_back(x);
    }
  }
  for (auto &e : v) {
    if (e >= l && e <= r) {
      s++;
    }
  }
  std::cout << std::max(r - l + 1 - s, 0) << '\n';
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
