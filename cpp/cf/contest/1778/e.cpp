#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

const int sz = 2e5 + 5, d = 30;
std::vector<std::vector<int>> g(sz), Tree(sz);
std::vector<int> a(sz), discover_time(sz), finish_time(sz), nodeOf(sz);
int tim;

struct BASIS {
  int basis[d];
  int sz;

  void init() {
    for (int i = 0; i < d; i++)
      basis[i] = 0;
    sz = 0;
  }

  void insertVector(int mask) {
    for (int i = d - 1; i >= 0; i--) {
      if (((mask >> i) & 1) == 0)
        continue;

      if (!basis[i]) {
        basis[i] = mask;
        ++sz;
        return;
      }
      mask ^= basis[i];
    }
  }

  void mergeBasis(const BASIS &from) {
    for (int i = d - 1; i >= 0; i--) {
      if (!from.basis[i])
        continue;

      insertVector(from.basis[i]);
    }
  }

  int findMax() {
    int ret = 0;
    for (int i = d - 1; i >= 0; i--) {
      if (!basis[i] || (ret >> i & 1))
        continue;

      ret ^= basis[i];
    }
    return ret;
  }
} in[sz], out, pre[sz], suf[sz];

void in_dfs(int u, int p) {
  in[u].insertVector(a[u]);
  discover_time[u] = ++tim;
  nodeOf[tim] = u;

  for (auto &v : g[u]) {
    if (v == p)
      continue;

    Tree[u].push_back(v);
    in_dfs(v, u);

    in[u].mergeBasis(in[v]);
  }
  finish_time[u] = tim;
}

inline bool in_subtree(int sub_root, int v) {
  return discover_time[sub_root] <= discover_time[v] &&
         finish_time[sub_root] >= finish_time[v];
}

int findChildOnPath(int sub_root, int v) {
  int lo = 0, hi = (int)Tree[sub_root].size() - 1;

  while (lo <= hi) {
    int mid = lo + hi >> 1, node = Tree[sub_root][mid];

    if (finish_time[node] < discover_time[v])
      lo = mid + 1;
    else if (discover_time[node] > discover_time[v])
      hi = mid - 1;
    else
      return node;
  }
}

void init(int n) {

  for (int i = 0; i <= n + 5; i++) {
    g[i].clear(), Tree[i].clear();
    in[i].init();
    pre[i].init(), suf[i].init();
  }
  tim = 0;
}

void solve() {
  int n;
  std::cin >> n;

  init(n);
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];

  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  in_dfs(1, -1);

  for (int i = 1; i <= n; i++) {
    pre[i].insertVector(a[nodeOf[i]]);
    pre[i].mergeBasis(pre[i - 1]);
  }

  for (int i = n; i >= 1; i--) {
    suf[i].insertVector(a[nodeOf[i]]);
    suf[i].mergeBasis(suf[i + 1]);
  }

  int q;
  std::cin >> q;

  while (q--) {
    int root, v;
    std::cin >> root >> v;

    if (root == v) {
      std::cout << in[1].findMax() << '\n';
    } else if (in_subtree(v, root)) {
      int child = findChildOnPath(v, root);

      out.init();
      out.mergeBasis(pre[discover_time[child] - 1]);
      out.mergeBasis(suf[finish_time[child] + 1]);
      std::cout << out.findMax() << '\n';
    } else
      std::cout << in[v].findMax() << '\n';
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
