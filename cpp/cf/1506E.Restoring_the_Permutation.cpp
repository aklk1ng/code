#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> q(n);
  for (int i = 0; i < n; i++) {
    std::cin >> q[i];
  }

  auto f = [&](std::vector<int> &t, bool ok) {
    std::set<int> l;
    for (int i = 1; i <= (int)t.size(); i++) {
      l.insert(i);
    }
    for (auto &e : t) {
      if (e != -1) {
        l.erase(e);
      }
    }
    int lst = -1;
    for (auto &e : t) {
      if (e == -1) {
        std::set<int>::const_iterator it;
        if (ok) {
          it = l.begin();
        } else {
          it = --l.lower_bound(lst);
        }
        e = *it;
        l.erase(it);
      } else {
        lst = e;
      }
    }
  };
  std::vector<int> res1(n, -1), res2(n, -1);
  for (int i = 0, lst = -1; i < n; lst = q[i], i++) {
    if (lst != q[i]) {
      res1[i] = q[i];
      res2[i] = q[i];
    }
  }
  f(res1, true);
  f(res2, false);
  for (auto &e : res1) {
    std::cout << e << " \n"[e == res1.back()];
  }
  for (auto &e : res2) {
    std::cout << e << " \n"[e == res2.back()];
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
