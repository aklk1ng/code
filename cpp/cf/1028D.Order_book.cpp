#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> a{{INT_MIN, 1}, {INT_MAX, 0}};
  std::set<int *> non{&a.begin()->second};
  for (int i = 0; i < n; i++) {
    std::string t;
    int x;
    std::cin >> t >> x;
    if (t == "ADD") {
      auto it = a.lower_bound(x);
      it--;
      int ways = it->second;
      auto m = a.emplace(x, ways).first;
      non.insert(&m->second);
    } else {
      auto m = a.find(x);
      auto it = std::prev(m);
      auto &w = it->second;
      w = (w + m->second) % mod;
      non.insert(&it->second);
      non.erase(&m->second);
      a.erase(m);
      for (auto e = non.begin(); e != non.end();) {
        if (*e == &it->second) {
          e++;
        } else {
          *(*e) = 0;
          e = non.erase(e);
        }
      }
    }
  }

  int ans = 0;
  for (auto &e : a) {
    ans = (ans + e.second) % mod;
  }
  std::cout << ans << '\n';
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
