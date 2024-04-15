#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> cnt(n + 1);
  std::vector<std::array<int, 2>> v;
  auto op = [&](int l, int r) {
    std::fill(cnt.begin(), cnt.end(), 0);
    for (int i = l; i <= r; i++) {
      if (a[i] <= n) {
        cnt[a[i]]++;
      }
    }
    int mx = 0;
    while (cnt[mx]) {
      mx++;
    }
    for (int i = l; i <= r; i++) {
      a[i] = mx;
    }
    v.push_back({l, r});
  };
  auto build = [&](auto self, int l, int r) -> void {
    if (l == r) {
      if (a[l]) {
        op(l, r);
      }
      return;
    }
    self(self, l, r - 1);
    if (a[r] != r - l) {
      op(l, r);
      self(self, l, r);
    }
  };
  int cur = 0, ans = 0;
  for (int s = 0; s < (1 << n); s++) {
    int tmp = 0;
    for (int l = 0; l < n; l++) {
      if (s & (1 << l)) {
        int r = l;
        while (r + 1 < n && (s & (1 << (r + 1)))) {
          r++;
        }
        tmp += (r - l + 1) * (r - l + 1);
        l = r;
      } else {
        tmp += a[l];
      }
    }
    if (tmp > ans) {
      ans = tmp;
      cur = s;
    }
  }
  for (int l = 0; l < n; l++) {
    if (cur & (1 << l)) {
      int r = l;
      while (r + 1 < n && (cur & (1 << (r + 1)))) {
        r++;
      }
      build(build, l, r);
      op(l, r);
      l = r;
    }
  }
  std::cout << ans << ' ' << v.size() << '\n';
  for (auto &[x, y] : v) {
    std::cout << x + 1 << ' ' << y + 1 << '\n';
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
