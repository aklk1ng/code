#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> l(n + 2), r(n + 2);
  for (int i = 1; i <= n; i++) {
    l[i] = min(a[i], l[i - 1] + 1);
  }
  for (int i = n; i >= 0; i--) {
    r[i] = min(a[i], r[i + 1] + 1);
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, min(l[i], r[i]));
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
