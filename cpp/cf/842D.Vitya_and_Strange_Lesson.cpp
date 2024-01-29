#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;
const int N = 3e5 + 5;
const int M = 20;

int n, m;
std::vector<int> a;

struct node {
  int nxt[2];
  int d;
  node() {
    nxt[0] = nxt[1] = -1;
    d = 0;
  }
};

node t[N * M];
int len = 1;

void add(int v, int num, int pos) {
  if (pos < 0) {
    t[v].d = 1;
    return;
  }
  int nxt = ((num >> pos) & 1);
  if (t[v].nxt[nxt] == -1) {
    t[v].nxt[nxt] = len++;
  }
  add(t[v].nxt[nxt], num, pos - 1);
  t[v].d = 0;

  if (t[v].nxt[0] != -1) {
    t[v].d += t[t[v].nxt[0]].d;
  }
  if (t[v].nxt[1] != -1) {
    t[v].d += t[t[v].nxt[1]].d;
  }
}

void get(int v, int num, int pos, int &ans) {
  if (v == -1) {
    return;
  }

  int nxt = ((num >> pos) & 1);
  if (t[t[v].nxt[nxt]].d == (1 << pos)) {
    nxt = 1 - nxt;
  }
  ans |= ((nxt ^ ((num >> pos) & 1)) << pos);
  get(t[v].nxt[nxt], num, pos - 1, ans);
}

void solve() {
  std::cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    add(0, a[i], M - 1);
  }

  int c = 0;
  for (int i = 0; i < m; i++) {
    int k;
    std::cin >> k;
    c ^= k;

    int ans = 0;
    get(0, c, M - 1, ans);
    std::cout << ans << '\n';
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
