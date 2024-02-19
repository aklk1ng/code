#include <bits/stdc++.h>
typedef long long ll;
const int SZ = 316;

struct Query {
  int l, r, num;
  bool operator<(const Query ohs) const { return r < ohs.r; }
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  ll res = 0;
  std::vector<int> cnt(1 << 20);
  auto add = [&](int v) {
    res += cnt[v ^ k];
    cnt[v]++;
  };
  auto del = [&](int v) {
    cnt[v]--;
    res -= cnt[v ^ k];
  };
  std::vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] ^ a[i - 1];
  }
  std::vector v(n / SZ + 2, std::vector<Query>());
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    l--, r++;
    v[l / SZ].push_back({l, r, i});
  }
  for (auto &e : v) {
    std::sort(e.begin(), e.end());
  }
  std::vector<ll> ans(m);
  for (int i = 0; i < (int)v.size(); i++) {
    int l, r;
    l = r = i * SZ;
    for (auto &e : v[i]) {
      while (r < e.r) {
        add(pre[r]);
        r++;
      }
      while (l < e.l) {
        del(pre[l]);
        l++;
      }
      while (l > e.l) {
        l--;
        add(pre[l]);
      }
      ans[e.num] = res;
    }
    for (int j = l; j < r; j++) {
      del(pre[j]);
    }
  }
  for (auto &e : ans) {
    std::cout << e << '\n';
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
