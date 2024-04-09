#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector childs(n + 1, std::vector<int>());
  std::vector<int> p(n + 1);
  for (int i = 2; i <= n; i++) {
    std::cin >> p[i];
    childs[p[i]].push_back(i);
  }

  std::vector<int> d(n + 1), h(n + 1), leaf;
  auto cmp = [&](int u, int v) { return d[u] < d[v]; };
  auto sort = [&](auto self, int v) -> void {
    d[v] = 0;
    if (v == 1) {
      h[v] = 0;
    } else {
      h[v] = h[p[v]] + 1;
    }
    for (int i = 0; i < (int)childs[v].size(); i++) {
      int u = childs[v][i];
      self(self, u);
      d[v] = std::max(d[v], d[u] + 1);
    }
    std::sort(childs[v].begin(), childs[v].end(), cmp);
  };
  sort(sort, 1);
  for (int i = 1; i <= n; i++) {
    if (childs[i].size() == 0) {
      int gap = 0;
      int v = i;
      while (v != 1) {
        int s = childs[p[v]].size();
        if (childs[p[v]][s - 1] == v) {
          v = p[v];
          gap++;
        } else {
          gap = gap + 1 - h[p[v]];
          break;
        }
      }
      leaf.push_back(gap);
    }
  }
  std::sort(leaf.begin(), leaf.end());
  int s = leaf.size();
  k++;
  int ans = 2 * (n - 1);
  for (int i = s - 1; i >= std::max(0, s - k); i--) {
    ans -= std::max(leaf[i], 0);
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
