#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 5e5 + 5;
const ll LINF = 1000000000000000005ll;

int n, q;
vector<int> a(N), b(N);
vector<ll> c(N);
vector st(N * 4, vector(2, vector<ll>(2)));

void Merge(int u, int l, int r) {
  int mid = (l + r) / 2, lc = u << 1, rc = u << 1 ^ 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      st[u][i][j] = min({st[lc][i][0] + st[rc][0][j], st[lc][i][1] + st[rc][1][j],
                         st[lc][i][0] + st[rc][1][j], st[lc][i][1] + st[rc][0][j] + c[mid]});
    }
  }
}

void init(int u = 1, int l = 1, int r = n) {
  if (l == r) {
    st[u][0][0] = a[l];
    st[u][1][1] = b[l];
    st[u][1][0] = st[u][0][1] = LINF;
    return;
  }
  int mid = (l + r) / 2, lc = u << 1, rc = u << 1 ^ 1;
  init(lc, l, mid);
  init(rc, mid + 1, r);
  Merge(u, l, r);
}

void upd(int p, int u = 1, int l = 1, int r = n) {
  if (l == r) {
    st[u][0][0] = a[l];
    st[u][1][1] = b[l];
    st[u][1][0] = st[u][0][1] = LINF;
    return;
  }
  int mid = (l + r) / 2, lc = u << 1, rc = u << 1 ^ 1;
  if (p <= mid) {
    upd(p, lc, l, mid);
  } else {
    upd(p, rc, mid + 1, r);
  }
  Merge(u, l, r);
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> c[i];
  }
  init();
  while (q--) {
    int p, x, y;
    ll z;
    cin >> p >> x >> y >> z;
    a[p] = x;
    b[p] = y;
    c[p] = z;
    upd(p);
    cout << min({st[1][0][0], st[1][0][1], st[1][1][0], st[1][1][1]}) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
