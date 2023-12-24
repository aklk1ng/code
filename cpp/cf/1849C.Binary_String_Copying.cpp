#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> lf(n), rg(n);
  lf[0] = -1;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      lf[i] = lf[i - 1];
    }
    if (s[i] == '0') {
      lf[i] = i;
    }
  }
  rg[n - 1] = n;
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1) {
      rg[i] = rg[i + 1];
    }
    if (s[i] == '1') {
      rg[i] = i;
    }
  }

  set<pair<int, int>> v;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    int t1 = rg[l - 1], t2 = lf[r - 1];
    if (t1 > t2) {
      v.insert({-1, -1});
    } else {
      v.insert({t1, t2});
    }
  }

  cout << v.size() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

  return 0;
}
