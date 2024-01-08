#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 5e5 + 5;
int n, q;
vector<int> a(N), b(N);
vector<ll> c(N), v(N), sv(N), mx(N * 4), lz(N * 4);

void init(int u = 1, int l = 1, int r = n) {
  lz[u] = 0;
  if (l == r) {
    mx[u] = sv[l];
  } else {
    int mid = (l + r) / 2;
    init(u << 1, l, mid);
    init(u << 1 ^ 1, mid + 1, r);
    mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
  }
}

void propo(int u) {
  if (lz[u] == 0) {
    return;
  }
  lz[u << 1] += lz[u];
  lz[u << 1 ^ 1] += lz[u];
  mx[u << 1] += lz[u];
  mx[u << 1 ^ 1] += lz[u];
  lz[u] = 0;
}

void incre(int s, int e, ll x, int u = 1, int l = 1, int r = n) {
  if (l >= s && r <= e) {
    mx[u] += x;
    lz[u] += x;
    return;
  }
  propo(u);
  int mid = (l + r) / 2;
  if (s <= mid) {
    incre(s, e, x, u << 1, l, mid);
  }
  if (e > mid) {
    incre(s, e, x, u << 1 ^ 1, mid + 1, r);
  }
  mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
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
  ll sma = 0;
  for (int i = n; i >= 1; i--) {
    v[i] = a[i] - b[i];
    sv[i] = v[i] + sv[i + 1];
    sma += a[i];
  }
  init();
  while (q--) {
    int p, x, y;
    ll z;
    cin >> p >> x >> y >> z;
    sma -= a[p];
    incre(1, p, -v[p]);
    a[p] = x;
    b[p] = y;
    v[p] = a[p] - b[p];
    sma += a[p];
    incre(1, p, v[p]);
    cout << sma - max(0LL, mx[1]) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
