#include <bits/stdc++.h>
typedef long long ll;
const int N = 3e5 + 5;

struct ap {
  ll base, dif;
};

ap add(ap a, ap b) {
  ap res;
  res.base = a.base + b.base;
  res.dif = a.dif + b.dif;
  return res;
}

ll convert(ap a, int n) {
  ll res = n * a.base;
  res += ((1LL * n * (n - 1)) / 2LL) * a.dif;
  return res;
}

std::vector<ll> st(4 * N), cost(N);
std::vector<ap> lazy(4 * N);
ap zero = {0, 0};

void pro(int node, int l, int r) {
  st[node] += convert(lazy[node], r - l + 1);
  if (l != r) {
    lazy[node * 2 + 1] = add(lazy[node * 2 + 1], lazy[node]);
    int mid = (l + r) / 2;
    int rg = (r - mid);
    lazy[node].base += rg * lazy[node].dif;
    lazy[node * 2] = add(lazy[node * 2], lazy[node]);
  }
  lazy[node] = zero;
}

void build(int node, int l, int r) {
  if (l == r) {
    st[node] = cost[l];
    lazy[node] = zero;
    return;
  }
  int mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  st[node] = st[node * 2] + st[node * 2 + 1];
  lazy[node] = zero;
  return;
}

void update(int node, int l, int r, int x, int y, ap val) {
  if (lazy[node].base || lazy[node].dif) {
    pro(node, l, r);
  }
  if (y < x || x > r || y < l) {
    return;
  }
  if (l >= x && r <= y) {
    st[node] += convert(val, r - l + 1);
    if (l != r) {
      lazy[node * 2 + 1] = add(lazy[node * 2 + 1], val);
      int mid = (l + r) / 2;
      int rg = (r - mid);
      val.base += rg * val.dif;
      lazy[node * 2] = add(lazy[node * 2], val);
    }
    return;
  }
  int mid = (l + r) / 2;
  update(node * 2 + 1, mid + 1, r, x, y, val);
  if (y > mid) {
    int rg = std::min(y, r) - mid;
    val.base += rg * val.dif;
  }
  update(node * 2, l, mid, x, y, val);
  st[node] = st[node * 2] + st[node * 2 + 1];
  return;
}

ll query(int node, int l, int r, int x, int y) {
  if (lazy[node].base || lazy[node].dif) {
    pro(node, l, r);
  }
  if (y < x || x > r || y < l) {
    return 0;
  }
  if (l >= x && r <= y) {
    return st[node];
  }
  int mid = (l + r) / 2;
  return query(node * 2, l, mid, x, y) + query(node * 2 + 1, mid + 1, r, x, y);
}

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::set<int> s;
  std::vector<ll> x(m), v(n + 1);
  for (int i = 0; i < m; i++) {
    std::cin >> x[i];
    s.insert(x[i]);
  }
  for (int i = 0; i < m; i++) {
    int t;
    std::cin >> t;
    cost[x[i]] = t;
    v[x[i]] = t;
  }

  for (int i = 1; i <= n; i++) {
    if (!cost[i]) {
      cost[i] = cost[i - 1];
    }
  }
  int dist = 0;
  for (int i = n; i > 0; i--) {
    if (s.find(i) != s.end()) {
      dist = 0;
    } else {
      dist++;
    }
    cost[i] *= dist;
  }
  build(1, 1, n);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int a, b;
      std::cin >> a >> b;
      v[a] = b;
      auto it = s.lower_bound(a);
      int nxt = *it;
      it--;
      int pre = *it;
      ap lf = {(v[pre] * (a - nxt)), 0};
      ap rg = {0, v[a] - v[pre]};
      update(1, 1, n, pre + 1, a, lf);
      update(1, 1, n, a + 1, nxt, rg);
      s.insert(a);
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << query(1, 1, n, l, r) << '\n';
    }
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
