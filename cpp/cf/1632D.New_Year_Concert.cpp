#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

struct node {
  node *l, *r;
  int v;
  node(node *tl, node *tr) {
    l = tl;
    r = tr;
    v = std::__gcd(tl->v, tr->v);
  }
  node(int x) {
    l = r = nullptr;
    v = x;
  }
};

std::vector<int> a;
node *build(int tl, int tr) {
  if (tl == tr - 1) {
    return new node(a[tl]);
  } else {
    int m = (tl + tr) / 2;
    return new node(build(tl, m), build(m, tr));
  }
}

int query(node *t, int tl, int tr, int l, int r) {
  if (l >= r) {
    return 0;
  }
  if (tl == l && tr == r) {
    return t->v;
  }
  int m = (tl + tr) / 2;
  return std::__gcd(query(t->l, tl, m, l, std::min(r, m)),
                    query(t->r, m, tr, std::max(l, m), r));
}

void solve() {
  int n;
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  node *t = build(0, n);
  std::vector segs(n, std::vector<int>());
  for (int i = 0; i < n; i++) {
    int l = i + 1, r = n, tans = i;
    while (l <= r) {
      int m = (l + r) / 2;
      if (query(t, 0, n, i, m) >= m - i) {
        tans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (query(t, 0, n, i, tans) == tans - i) {
      segs[tans - 1].push_back(i);
    }
  }

  int ans = 0, pi = -1;
  for (int i = 0; i < n; i++) {
    for (auto &e : segs[i]) {
      if (e > pi) {
        ans++;
        pi = i;
      }
    }
    std::cout << ans << ' ';
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
