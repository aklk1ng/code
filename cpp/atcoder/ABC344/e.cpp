#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;

  std::list<int> a;
  std::map<int, std::list<int>::iterator> m;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a.emplace_back(x);
    m[x] = --a.end();
  }

  int q;
  std::cin >> q;
  int o, x, y;
  while (q--) {
    std::cin >> o;
    if (o ^ 2) {
      std::cin >> x >> y;
      std::list<int>::iterator it = m[x];
      it++;
      a.emplace(it, y);
      m[y] = --it;
    } else {
      std::cin >> x;
      a.erase(m[x]);
    }
  }

  for (auto &e : a) {
    std::cout << e << " \n"[e == a.back()];
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
