#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
  }

  int old = n;
  for (int _ = 0; _ < 2; _++) {
    std::map<ll, std::vector<ll>> m;
    for (int i = 0; i < n; i++) {
      m[l[i]].push_back(r[i]);
    }
    std::vector<ll> nl, nr;
    auto it = m.begin();
    std::multiset<ll> s;
    ll tmp = LONG_MIN;
    while (true) {
      if (s.empty()) {
        if (it == m.end()) {
          break;
        }
        tmp = it->first;
      }
      while (it != m.end() && tmp == it->first) {
        s.insert(it->second.begin(), it->second.end());
        it++;
      }
      nl.push_back(tmp);
      nr.push_back(*s.begin());
      s.erase(s.begin());
      tmp++;
      while (!s.empty() && *s.begin() < tmp) {
        s.erase(s.begin());
      }
    }
    std::swap(l, nl);
    std::swap(r, nr);
    n = l.size();
    for (int i = 0; i < n; i++) {
      l[i] *= -1;
      r[i] *= -1;
      std::swap(l[i], r[i]);
    }
  }
  std::sort(l.begin(), l.end());
  std::sort(r.begin(), r.end());
  std::vector<ll> ans(old + 1);
  ll mi = LONG_MIN, mx = LONG_MIN;
  int pl = 0, pr = 0, k = 0;
  while (pl < n || pr < n) {
    ll wait = std::min(pl < n ? l[pl] - mi : LONG_MAX, pr < n ? r[pr] - mx : LONG_MAX);
    ans[k] += wait;
    mi += wait;
    mx += wait;
    while (pl < n && l[pl] == mi) {
      k++;
      mi++;
      pl++;
    }
    while (pr < n && r[pr] == mx) {
      ans[k]++;
      k--;
      mx++;
      pr++;
    }
  }
  for (int i = n; i > 1; i--) {
    ans[i - 1] += ans[i];
  }
  for (int i = 1; i <= old; i++) {
    std::cout << ans[i] << '\n';
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
