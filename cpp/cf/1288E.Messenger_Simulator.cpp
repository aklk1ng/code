#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 6e5 + 5;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> mi(n);
  std::iota(mi.begin(), mi.end(), 0);
  std::vector<int> mx(mi);

  std::vector<int> a(m);
  for (int i = 0; i < m; i++) {
    std::cin >> a[i];
    a[i]--;
    mi[a[i]] = 0;
  }

  std::vector<int> f(N);
  auto upd = [&](int x, int val) {
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
      f[i] += val;
    }
  };
  auto get = [&](int x) {
    int res = 0;
    for (int i = x; i < N; i |= i + 1) {
      res += f[i];
    }
    return res;
  };

  std::vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[i] = n - i - 1;
  }
  for (int i = 0; i < n; i++) {
    upd(i, 1);
  }

  for (int i = 0; i < m; i++) {
    mx[a[i]] = std::max(mx[a[i]], get(pos[a[i]] + 1));
    upd(pos[a[i]], -1);
    pos[a[i]] = i + n;
    upd(pos[a[i]], 1);
  }
  for (int i = 0; i < n; i++) {
    mx[i] = std::max(mx[i], get(pos[i] + 1));
  }

  for (int i = 0; i < n; i++) {
    std::cout << mi[i] + 1 << ' ' << mx[i] + 1 << '\n';
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
