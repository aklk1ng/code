#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

struct event {
  event(int _t, int _s, int _e, int _isIn) : t(_t), s(_s), e(_e), isIn(_isIn) {}
  int t, s, e, isIn;
  bool operator<(const event &rhs) {
    if (t == rhs.t) {
      return isIn < rhs.isIn;
    }
    return t < rhs.t;
  };
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> sa(n), ea(n), sb(n), eb(n);
  for (int i = 0; i < n; i++) {
    std::cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
  }

  auto check = [&](std::vector<int> &a, std::vector<int> &b,
                   std::vector<int> &c, std::vector<int> &d) {
    std::multiset<int> s, e;
    std::vector<event> es;

    for (int i = 0; i < n; i++) {
      es.emplace_back(a[i], c[i], d[i], 1);
      es.emplace_back(b[i] + 1, c[i], d[i], 0);
    }
    std::sort(es.begin(), es.end());

    for (int i = 0; i < 2 * n; i++) {
      if (es[i].isIn) {
        if (!s.empty()) {
          int mx = *s.rbegin(), mi = *e.begin();
          if (mx > es[i].e || mi < es[i].s) {
            return false;
          }
        }
        s.insert(es[i].s);
        e.insert(es[i].e);
      } else {
        s.erase(s.find(es[i].s));
        e.erase(e.find(es[i].e));
      }
    }
    return true;
  };
  if (check(sa, ea, sb, eb) && check(sb, eb, sa, ea)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
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
