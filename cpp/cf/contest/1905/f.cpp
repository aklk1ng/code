#include <bits/stdc++.h>
typedef long long ll;

struct aint {
  std::vector<std::pair<int, int>> a;
  std::vector<int> lazy;

  void resize(int n) {
    a = std::vector<std::pair<int, int>>(4 * n);
    lazy = std::vector<int>(4 * n);
  }

  void init(int node, int l, int r) {
    a[node].second = (r - l + 1);
    if (l != r) {
      int mid = (l + r) / 2;
      init(2 * node, l, mid);
      init(2 * node + 1, mid + 1, r);
    }
  }

  void prop(int node, int l, int r) {
    a[node].first += lazy[node];
    if (l != r) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  std::pair<int, int> merge(std::pair<int, int> lhs, std::pair<int, int> rhs) {
    if (lhs.first == rhs.first) {
      return {lhs.first, lhs.second + rhs.second};
    }
    return std::min(lhs, rhs);
  }

  void update(int node, int l, int r, int st, int d, int val) {
    prop(node, l, r);
    if (r < st || l > d) {
      return;
    }
    if (st <= l && d >= r) {
      lazy[node] += val;
      prop(node, l, r);
      return;
    }
    int mid = (l + r) / 2;
    update(2 * node, l, mid, st, d, val);
    update(2 * node + 1, mid + 1, r, st, d, val);
    a[node] = merge(a[2 * node], a[2 * node + 1]);
  }
};

struct bit {
  std::vector<int> a;

  void resize(int n) { a = std::vector<int>(n + 1); }

  void update(int pos, int val) {
    int n = a.size() - 1;
    for (int i = pos; i <= n; i += i & (-i)) {
      a[i] += val;
    }
  }

  int query(int pos) {
    int ans = 0;
    for (int i = pos; i; i -= i & (-i)) {
      ans += a[i];
    }
    return ans;
  }

  int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] != i) {
      ok = false;
    }
  }
  if (ok) {
    std::cout << n - 2 << '\n';
    return;
  }
  std::vector<std::pair<int, int>> qui(n + 1);
  std::stack<int> s;
  bit tree;
  tree.resize(n);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    if (!s.empty()) {
      qui[i].first = s.top();
    }
    if (tree.query(a[i], n) > 1) {
      qui[i].first = 0;
    }
    tree.update(a[i], 1);
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  tree.resize(n);
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] > a[i]) {
      s.pop();
    }
    if (!s.empty()) {
      qui[i].second = s.top();
    }
    if (tree.query(1, a[i]) > 1) {
      qui[i].second = 0;
    }
    tree.update(a[i], 1);
    s.push(i);
  }

  aint lg;
  lg.resize(n);
  lg.init(1, 1, n);
  auto upd = [&](int ind, int sign) {
    lg.update(1, 1, n, std::min(ind, a[ind]), std::max(ind, a[ind]), sign);
  };
  auto cnt = [&]() {
    if (lg.a[1].first == 1) {
      return lg.a[1].second;
    }
    return 0;
  };
  auto swap = [&](int i, int j) {
    upd(i, -1);
    upd(j, -1);
    std::swap(a[i], a[j]);
    upd(i, 1);
    upd(j, 1);
  };
  for (int i = 1; i <= n; i++) {
    upd(i, 1);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (qui[i].first && qui[i].second) {
      swap(qui[i].first, qui[i].second);
      ans = std::max(ans, cnt());
      swap(qui[i].first, qui[i].second);
    }
  }
  std::vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int qui1 = i;
    int qui2 = pos[i];
    swap(qui1, qui2);
    ans = std::max(ans, cnt());
    swap(qui1, qui2);
  }

  std::cout << ans << '\n';
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
