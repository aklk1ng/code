#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), pos(n + 1), nxt(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    pos[i] = n + 1;
  }

  for (int i = n; i >= 0; i--) {
    nxt[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  int x = 0, y = 0;
  int ans = 0;
  for (int z = 1; z <= n; z++) {
    if (a[x] == a[z]) {
      ans += a[y] != a[z];
      y = z;
    } else if (a[y] == a[z]) {
      ans += a[x] != a[z];
      x = z;
    } else if (nxt[x] < nxt[y]) {
      ans += a[x] != a[z];
      x = z;
    } else {
      ans += a[y] != a[z];
      y = z;
    }
  }
  cout << ans << '\n';
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
