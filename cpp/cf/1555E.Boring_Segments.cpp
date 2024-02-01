#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

std::vector<int> t, ps;
struct seg {
  int l, r, w;
};

void push(int v) {
  if (v * 2 + 1 < (int)ps.size()) {
    ps[v * 2] += ps[v];
    ps[v * 2 + 1] += ps[v];
  }
  t[v] += ps[v];
  ps[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val) {
  push(v);
  if (L >= R) {
    return;
  }
  if (l == L && r == R) {
    ps[v] += val;
    push(v);
    return;
  }
  int m = (l + r) / 2;
  upd(2 * v, l, m, L, std::min(m, R), val);
  upd(2 * v + 1, m, r, std::max(m, L), R, val);
  t[v] = std::min(t[2 * v], t[2 * v + 1]);
}

int get() { return t[1] + ps[1]; }

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<seg> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].l >> a[i].r >> a[i].w;
    a[i].l--, a[i].r--;
  }
  m--;
  std::sort(a.begin(), a.end(),
            [](const seg &x, const seg &y) { return x.w < y.w; });
  t.resize(4 * m);
  ps.resize(4 * m);
  int ans = INF;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && get() == 0) {
      upd(1, 0, m, a[j].l, a[j].r, 1);
      j++;
    }
    if (!get()) {
      break;
    }
    ans = std::min(ans, a[j - 1].w - a[i].w);
    upd(1, 0, m, a[i].l, a[i].r, -1);
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
