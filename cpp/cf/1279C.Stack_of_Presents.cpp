#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector<int> pos(a);
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }

  int t = -1;
  ll ans = m;
  for (int i = 0; i < m; i++) {
    if (pos[b[i]] > t) {
      ans += 2 * (pos[b[i]] - i);
      t = pos[b[i]];
    }
  }
  cout << ans << '\n';
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
