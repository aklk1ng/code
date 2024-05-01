#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }

  std::vector<int> t(4 * n), p(4 * n);
  std::vector<std::vector<int>> pos(n);
  auto push = [&](int v) {
    if (v * 2 + 2 >= t.size()) {
      return;
    }
    t[2 * v + 1] += p[v];
    p[2 * v + 1] += p[v];
    t[2 * v + 2] += p[v];
    p[2 * v + 2] += p[v];
    p[v] = 0;
  };
  auto upd = [&](auto self, int v, int l, int r, int L, int R, int x) -> void {
    if (L >= R) {
      return;
    }
    if (l == L && r == R) {
      t[v] += x;
      p[v] += x;
      return;
    }
    int m = (l + r) / 2;
    push(v);
    self(self, v * 2 + 1, l, m, l, std::min(m, R), x);
    self(self, v * 2 + 2, m, r, std::max(m, L), R, x);
    t[v] = std::min(t[v * 2 + 1], t[v * 2 + 2]);
  };
  auto get = [&](auto self, int v, int l, int r, int L, int R) -> int {
    if (L >= R) {
      return 1e9;
    }
    if (l == L && r == R) {
      return t[v];
    }
    int m = (l + r) / 2;
    push(v);
    return std::min(self(self, 2 * v + 1, l, m, l, std::min(m, R)),
                    self(self, 2 * v + 2, m, r, std::max(m, L), R));
  };
  int ans = 0, st = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    pos[x].push_back(i);
    int k = pos[x].size();
    if (k > 0) {
      upd(upd, 0, 0, n, st, pos[x][k - 1] + 1, 1);
    }
    if (k > 1) {
      upd(upd, 0, 0, n, st, pos[x][k - 2] + 1, -2);
    }
    if (k > 2) {
      upd(upd, 0, 0, n, st, pos[x][k - 3] + 1, 1);
    }
    if (get(get, 0, 0, n, st, i + 1) == 0) {
      ans++;
      st = i + 1;
    }
  }
  std::cout << ans << '\n';
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
