#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    int q;
    std::cin >> q;
    while (q--) {
      int pos, val;
      std::cin >> pos >> val;
      std::cout << val << " \n"[q == 0];
    }
    return;
  }

  std::multiset<int> s, delta;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
  }
  for (auto it = ++s.begin(); it != s.end(); it++) {
    auto pre = std::prev(it);
    delta.insert(*it - *pre);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int pos, val;
    std::cin >> pos >> val;
    auto it = s.find(a[pos - 1]);
    auto nxt = std::next(it), pre = std::prev(it);
    if (it == s.begin()) {
      delta.erase(delta.find(*nxt - *it));
    } else if (it == --s.end()) {
      delta.erase(delta.find(*it - *pre));
    } else {
      delta.erase(delta.find(*nxt - *it));
      delta.erase(delta.find(*it - *pre));
      delta.insert(*nxt - *pre);
    }
    s.erase(it);
    s.insert(val);
    it = s.find(val);
    nxt = std::next(it), pre = std::prev(it);
    if (it == s.begin()) {
      delta.insert(*nxt - *it);
    } else if (it == --s.end()) {
      delta.insert(*it - *pre);
    } else {
      delta.insert(*nxt - *it);
      delta.insert(*it - *pre);
      delta.erase(delta.find(*nxt - *pre));
    }
    a[pos - 1] = val;
    std::cout << *std::prev(s.end()) + *std::prev(delta.end()) << " \n"[q == 0];
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
