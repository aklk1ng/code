#include <bits/stdc++.h>
typedef long long ll;

struct event {
  ll x;
  int c;
  event() {}
  event(ll _x, int _c) : x(_x), c(_c) {}
};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
    r[i] += 2;
  }

  auto check = [&](ll len) -> std::pair<ll, int> {
    if (!len) {
      return {0, n};
    }
    static std::vector<event> es;
    for (int i = 1; i <= n; i++) {
      if (r[i] - len > l[i]) {
        es.push_back({l[i], 1});
        es.push_back({r[i] - len, -1});
      }
    }
    std::sort(es.begin(), es.end(),
              [](const event &a, const event &b) { return a.x < b.x; });
    std::reverse(es.begin(), es.end());
    int cnt = 0, mx = 0;
    ll bst = 0;
    while (!es.empty()) {
      ll x = es.back().x;
      while (!es.empty() && es.back().x == x) {
        cnt += es.back().c;
        es.pop_back();
      }
      if (cnt > mx) {
        mx = cnt;
        bst = x;
      }
    }
    return {bst, mx};
  };
  auto get = [&](ll len) {
    if (len == 0) {
      std::vector<int> res(n);
      std::iota(res.begin(), res.end(), 1);
      return res;
    }
    ll pos = check(len).first;
    std::vector<int> res;
    for (int i = 1; i <= n; i++) {
      if (pos >= l[i] && pos < r[i] - len) {
        res.push_back(i);
      }
    }
    return res;
  };
  ll lf = 0, rg = LONG_MAX;
  while (rg - lf > 1) {
    ll mid = (lf + rg) / 2;
    if (check(mid).second >= k) {
      lf = mid;
    } else {
      rg = mid;
    }
  }

  std::vector<int> ans = get(lf);
  std::cout << lf << '\n';
  ans.resize(k);
  for (auto &e : ans) {
    std::cout << e << " \n"[e == ans.back()];
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
