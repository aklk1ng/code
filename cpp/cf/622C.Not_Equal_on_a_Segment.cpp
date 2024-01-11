#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), l(m), r(m), x(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> x[i];
    l[i]--, r[i]--;
  }
  vector<int> z(n);
  z[0] = -1;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      z[i] = i - 1;
    } else {
      z[i] = z[i - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    if (a[r[i]] != x[i]) {
      cout << r[i] + 1 << '\n';
    } else if (z[r[i]] >= l[i]) {
      cout << z[r[i]] + 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();

  return 0;
}
