#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

template <class Info>
struct Fenwick {
  std::vector<Info> t;
  int n;

  Fenwick(int _n = 0) : n(_n) { t.resize(_n); };

  void add(int x, const Info &v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      t[i - 1] = t[i - 1] + v;
    }
  }

  Info sum(int x) {
    x++;
    Info res = Info();
    for (int i = x; i > 0; i -= i & -i) {
      res = res + t[i - 1];
    }
    return res;
  }

  Info range(int l, int r) { return sum(r) - sum(l - 1); }
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), pos(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  const int K = 19;
  std::vector<ll> res(q);
  std::vector<std::vector<std::pair<int, int>>> qy(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    std::swap(l, r);
    l = n - l - 1;
    r = n - r - 1;
    qy[r].emplace_back(l, i);
  }
  std::vector<ll> dp(n + 1);
  Fenwick<ll> f(n);
  for (int r = 0; r < n; r++) {
    int x = a[r];
    dp[x] = 1;
    for (int y = x; y <= n; y += x) {
      if (pos[y] > pos[x]) {
        continue;
      }
      for (int z = 2 * y; z <= n; z += y) {
        if (pos[z] > pos[y]) {
          continue;
        }
        dp[z] += dp[y];
      }
    }
    for (int y = x; y <= n; y += x) {
      f.add(pos[y], dp[y]);
      dp[y] = 0;
    }
    for (auto &[l, i] : qy[r]) {
      res[i] += f.range(l, r);
    }
  }
  for (int i = 0; i < q; i++) {
    std::cout << res[i] << " \n"[i == q - 1];
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
