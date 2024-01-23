#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  std::vector<std::pair<int, int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    pos[i + 1].first = pos[i].first + (s[i] == 'R') - (s[i] == 'L');
    pos[i + 1].second = pos[i].second + (s[i] == 'U') - (s[i] == 'D');
  }

  std::map<std::pair<int, int>, std::vector<int>> m;
  for (int i = 0; i <= n; i++) {
    m[pos[i]].push_back(i);
  }
  auto check = [&](std::pair<int, int> p, int l, int r) {
    if (!m.count(p)) {
      return false;
    }
    auto it = std::lower_bound(m[p].begin(), m[p].end(), l);
    return it != m[p].end() && *it <= r;
  };

  while (q--) {
    int x, y, l, r;
    std::cin >> x >> y >> l >> r;
    int nx = pos[r].first + pos[l - 1].first - x;
    int ny = pos[r].second + pos[l - 1].second - y;
    std::cout << ((check({x, y}, 0, l - 1) || check({nx, ny}, l, r - 1) ||
                   check({x, y}, r, n))
                      ? "YES"
                      : "NO")
              << '\n';
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
