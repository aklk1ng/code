#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  auto sign = [&](int x) { return x % 2 ? -1 : 1; };
  auto abs = [&](ll x) { return x > 0 ? x : -x; };
  ll sum = 0;
  std::set<ll> s;
  std::vector<int> b(m);
  auto cal = [&](ll x) {
    auto it = s.lower_bound(x);
    if (it == s.end()) {
      it--;
    }
    ll res = abs(*it - x);
    if (it != s.begin()) {
      it--;
    }
    return std::min(res, abs(*it - x));
  };
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    sum += a * sign(i);
  }
  ll cur = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    cur += sign(i + 1) * b[i];
  }
  s.insert(cur);
  for (int i = n; i < m; i++) {
    std::cin >> b[i];
    cur += b[i - n];
    cur = -cur;
    cur += sign(n) * b[i];
    s.insert(cur);
  }
  std::cout << cal(-sum) << '\n';

  while (q--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    if ((r - l) % 2 == 0) {
      sum += (l % 2 ? x : -x);
    }
    std::cout << cal(-sum) << '\n';
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
