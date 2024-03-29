#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

struct DynamicMaxSubarraySum {
  struct node {
    ll pre, suf, val, sum;
  };
  int N;
  ll neutral;
  vector<node> t;

  DynamicMaxSubarraySum(int n, ll value) {
    neutral = value;
    N = n;
    t.resize(4 * N);
    for (int i = 0; i < 4 * N; i++) {
      t[i] = {0, 0, 0, 0};
    }
    build(1, 0, N - 1);
  }

  void build(int i, int l, int r) {
    if (l == r) {
      t[i].pre = t[i].suf = t[i].val = t[i].sum = neutral;
      return;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = merge(t[2 * i], t[2 * i + 1]);
  }

  node merge(node a, node b) {
    return {max(a.pre, a.sum + b.pre), max(b.suf, b.sum + a.suf),
            max({a.val, b.val, a.suf + b.pre}), a.sum + b.sum};
  }

  void modify(int i, int l, int r, int pos, ll val) {
    if (l > pos || r < pos) {
      return;
    }
    if (l == pos && r == pos) {
      t[i].pre = t[i].suf = t[i].val = t[i].sum = val;
      return;
    }
    int mid = (l + r) / 2;
    modify(2 * i, l, mid, pos, val);
    modify(2 * i + 1, mid + 1, r, pos, val);
    t[i] = merge(t[2 * i], t[2 * i + 1]);
  }

  node query(int i, int l, int r, int tl, int tr) {
    if (l > tr || r < tl) {
      return {0, 0, 0, 0};
    }
    if (l >= tl && r <= tr) {
      return t[i];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * i, l, mid, tl, tr), query(2 * i + 1, mid + 1, r, tl, tr));
  }

  void modify(int pos, int val) { modify(1, 0, N - 1, pos, val); }

  node query(int l, int r) { return query(1, 0, N - 1, l, r); }

  node query(int pos) { return query(1, 0, N - 1, pos, pos); }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++) {
    m[a[i]].push_back(i);
  }
  DynamicMaxSubarraySum st(n, -1);

  ll mx = 0, ans = -1;
  for (auto &i : m) {
    vector<int> v = i.second;
    for (auto &x : v) {
      st.modify(x, 1);
    }
    if (mx < st.query(0, n - 1).val) {
      ans = i.first;
      mx = st.query(0, n - 1).val;
    }
    for (auto &x : v) {
      st.modify(x, -1);
    }
  }
  int ansl = -1, ansr = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == ans) {
      a[i] = 1;
    } else {
      a[i] = -1;
    }
  }
  ll sum = 0, last = 0;
  mx = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum > mx) {
      mx = sum;
      ansr = i;
      ansl = last;
    }
    if (sum <= 0) {
      last = i + 1;
      sum = 0;
    }
  }
  cout << ans << ' ' << ansl + 1 << ' ' << ansr + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
