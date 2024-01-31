#include <bits/stdc++.h>
#include <charconv>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::set<int> pos;
  std::multiset<int> gaps;

  auto add = [&](int p) {
    auto it = pos.insert(p).first;
    if (std::next(it) != pos.end()) {
      gaps.insert(*std::next(it) - p);
    }
    if (it != pos.begin()) {
      gaps.insert(p - *std::prev(it));
      if (std::next(it) != pos.end()) {
        gaps.erase(gaps.find(*std::next(it) - *std::prev(it)));
      }
    }
  };
  auto erase = [&](int p) {
    auto it = pos.find(p);
    if (std::next(it) != pos.end()) {
      gaps.erase(gaps.find(*std::next(it) - p));
    }
    if (it != pos.begin()) {
      gaps.erase(gaps.find(p - *std::prev(it)));
      if (std::next(it) != pos.end()) {
        gaps.insert(*std::next(it) - *std::prev(it));
      }
    }
    pos.erase(it);
  };
  auto query = [&]() {
    if ((int)pos.size() <= 2) {
      return 0;
    }
    return *(--pos.end()) - *pos.begin() - *(--gaps.end());
  };

  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;
    add(p);
  }
  std::cout << query() << '\n';

  while (q--) {
    int op, x;
    std::cin >> op >> x;
    if (!op) {
      erase(x);
    } else {
      add(x);
    }
    std::cout << query() << '\n';
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
