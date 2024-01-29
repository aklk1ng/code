#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

struct dsu {
  std::vector<int> p, lvl;
  dsu(int n) {
    p.resize(n);
    lvl.assign(n, 0);
    std::iota(p.begin(), p.end(), 0);
  }

  int get(int i) {
    if (i == p[i]) {
      return i;
    }
    return p[i] = get(p[i]);
  }

  bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) {
      return false;
    }
    if (lvl[a] < lvl[b]) {
      std::swap(a, b);
    }
    p[b] = a;
    if (lvl[a] == lvl[b]) {
      lvl[a]++;
    }
    return true;
  }

  bool reachable(int a, int b) { return get(a) == get(b); }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> h(n);
  for (int i = 0; i < n; i++) {
    std::cin >> h[i].first;
  }
  for (int i = 0; i < n; i++) {
    h[i].second = i;
  }

  dsu graph(n);
  std::vector<std::vector<int>> sl(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    if (h[u].first > h[v].first) {
      sl[u].emplace_back(v);
    } else {
      sl[v].emplace_back(u);
    }
  }

  int q;
  std::cin >> q;
  std::vector req(q, std::pair<std::pair<int, int>, std::pair<int, int>>());
  for (auto &e : req) {
    std::cin >> e.second.first >> e.second.second >> e.first.first;
    e.second.first--, e.second.second--;
    e.first.first += h[e.second.first].first;
  }
  for (int i = 0; i < q; i++) {
    req[i].first.second = i;
  }

  std::sort(h.begin(), h.end());
  std::sort(req.begin(), req.end());
  std::vector<bool> ans(q);
  int j = 0;
  for (auto &e : req) {
    while (j < n && h[j].first <= e.first.first) {
      for (auto &u : sl[h[j].second]) {
        graph.unite(h[j].second, u);
      }
      j++;
    }
    ans[e.first.second] = graph.reachable(e.second.first, e.second.second);
  }

  for (auto e : ans) {
    std::cout << (e ? "YES" : "NO") << '\n';
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
    std::cout << " \n"[T > 0];
  }

  return 0;
}
