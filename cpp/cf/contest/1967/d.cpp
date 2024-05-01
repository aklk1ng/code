#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int MAXM = 1e6 + 6;
int dep[MAXM], id[MAXM], dfn[MAXM], to[MAXM], sz[MAXM], tot = 0;
std::vector<int> ch[MAXM];

void dfs(int u) {
  sz[u] = 1, dfn[u] = ++tot;
  for (int v : ch[u]) {
    dep[v] = dep[u] + 1, id[v] = id[u];
    dfs(v), sz[u] += sz[v];
  }
}

inline bool inSub(int u, int v) /* v \in u ? */ {
  return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + sz[u];
}

constexpr int INF = 0x3f3f3f3f;

inline int query(int u, int v) /* u -> v */ {
  if (u == v)
    return 0;
  if (id[u] != id[v])
    return INF;
  int res = INF;
  if (inSub(v, u))
    res = dep[u] - dep[v];
  if (inSub(v, to[id[u]]))
    res = std::min(dep[u] - dep[v] + dep[to[id[u]]] + 1, res);
  // printf("query(%d, %d) = %d\n", u, v, res);
  return res;
}

#define MAXN 1000001
int a[MAXN], N, M;

bool check(int val) {
  // printf("check %d\n", val);
  int lst = 1;
  for (int i = 1; i <= N; ++i) {
    while (lst <= M && query(a[i], lst) > val)
      ++lst;
    if (lst > M)
      return false;
  }
  return true;
}

namespace DSU {
int fa[MAXM];

void inis(int n) {
  for (int i = 1; i <= n; ++i)
    fa[i] = i;
}

inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

inline bool merge(int x, int y) {
  if (find(x) == find(y))
    return false;
  fa[fa[x]] = fa[y];
  return true;
}
}; // namespace DSU

using namespace DSU;

void solve() {
  std::cin >> N >> M;
  inis(M);
  for (int i = 1; i <= N; i++) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= M; i++) {
    dep[i] = id[i] = dfn[i] = to[i] = sz[i] = 0;
    ch[i].clear();
  }
  tot = 0;
  for (int i = 1; i <= M; i++) {
    int p;
    std::cin >> p;
    if (merge(i, p)) {
      ch[p].push_back(i);
    } else {
      to[i] = p;
    }
  }
  for (int i = 1; i <= M; i++) {
    if (to[i] > 0) {
      id[i] = i;
      dfs(i);
    }
  }
  if (!check(M)) {
    std::cout << "-1\n";
    return;
  }
  int l = 0, r = M;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  std::cout << r << '\n';
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
