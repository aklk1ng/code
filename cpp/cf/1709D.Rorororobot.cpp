#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int l = 0;
  while ((1 << l) <= m) {
    l++;
  }
  vector st(l, vector<int>(m));
  for (int i = 0; i < m; i++) {
    st[0][i] = a[i];
  }
  for (int j = 1; j < l; j++) {
    for (int i = 0; i < m; i++) {
      st[j][i] = st[j - 1][i];
      if (i + (1 << (j - 1)) < m) {
        st[j][i] = max(st[j][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  vector<int> pw(m + 1);
  for (int i = 2; i <= m; i++) {
    pw[i] = pw[i / 2] + 1;
  }
  auto cal = [&](int l, int r) {
    if (l > r) {
      swap(l, r);
    }
    r++;
    int len = pw[r - l];
    return max(st[len][l], st[len][r - (1 << len)]);
  };

  int q;
  cin >> q;
  while (q--) {
    int xs, ys, xf, yf, k;
    cin >> xs >> ys >> xf >> yf >> k;
    xs--, ys--, xf--, yf--;
    if (ys % k != yf % k || xs % k != xf % k) {
      cout << "No\n";
      continue;
    }
    cout << (cal(ys, yf) <= (n - xs - 1) / k * k + xs ? "Yes" : "No") << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
