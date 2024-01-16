#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  n = min(n, m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= m;
  }
  vector<int> p(m, -1), np(m, -1);
  for (int t = 0; t < n && p[0] == -1; t++) {
    int v = a[t];
    copy(p.begin(), p.end(), np.begin());
    if (np[v] == -1) {
      np[v] = t;
    }
    for (int i = 0; i < m; i++) {
      if (p[i] != -1 && p[(i + v) % m] == -1) {
        np[(i + v) % m] = t;
      }
    }
    copy(np.begin(), np.end(), p.begin());
  }
  if (p[0] == -1) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  if (false) {
    cin >> tt;
  }
  while (tt--) {
    solve();
  }

  return 0;
}
