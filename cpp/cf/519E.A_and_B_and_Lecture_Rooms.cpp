#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

int n;
std::vector g(N, std::vector<int>()), anc(N, std::vector<int>(30));
std::vector<int> depth(N), size(N), tin(N), tout(N);
int timer;

void dfs(int v, int p = 1, int d = 0) {
  depth[v] = d;
  size[v] = 1;
  tin[v] = timer++;

  anc[v][0] = p;
  for (int i = 1; i < 30; i++) {
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
  }
  for (size_t i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to != p) {
      dfs(to, v, d + 1);
      size[v] += size[to];
    }
  }

  tout[v] = timer++;
}

bool ancestor(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int up(int a, int b) {
  for (int i = 29; i >= 0; i--) {
    if (!ancestor(anc[a][i], b)) {
      a = anc[a][i];
    }
  }
  return a;
}

int lca(int a, int b) {
  int res = -1;

  if (ancestor(a, b)) {
    res = a;
  } else if (ancestor(b, a)) {
    res = b;
  } else {
    res = anc[up(a, b)][0];
  }

  return res;
}

int query(int a, int b) {
  int l = lca(a, b);
  int res = -1;

  if (a == b) {
    res = n;
  } else if (depth[a] - depth[l] == depth[b] - depth[l]) {
    a = up(a, l);
    b = up(b, l);
    res = n - size[a] - size[b];
  } else {
    if (depth[a] < depth[b]) {
      std::swap(a, b);
    }
    int to = a;
    int dist = depth[a] + depth[b] - 2 * depth[l];
    if (dist % 2) {
      res = 0;
    } else {
      dist /= 2;
      for (int i = 29; i >= 0; i--) {
        if (depth[a] - depth[anc[to][i]] < dist) {
          to = anc[to][i];
        }
      }
      int mid = anc[to][0];
      res = size[mid] - size[to];
    }
  }

  return res;
}

void solve() {
  std::cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);

  int q;
  std::cin >> q;
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << query(a, b) << '\n';
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
