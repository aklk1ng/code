#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::set<int> q[2];
  int id = 0;
  q[id].insert(x);
  while (m--) {
    int op;
    char c;
    std::cin >> op >> c;
    while (!q[id].empty()) {
      int u = *(q[id].begin());
      q[id].erase(u);
      if (c == '?' || c == '0') {
        q[id ^ 1].insert((u + op - 1) % n + 1);
      }
      if (c == '?' || c == '1') {
        q[id ^ 1].insert((u - op - 1 + n) % n + 1);
      }
    }
    id ^= 1;
  }

  std::cout << q[id].size() << '\n';
  for (auto &e : q[id]) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
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
