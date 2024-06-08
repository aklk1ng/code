#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);

  int mx = -1, mi = INF;
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mi = min(mi, a[i]);
  }
  if (mx == mi) {
    cout << -1 << '\n';
  } else {
    for (int i = 1; i <= n; i++) {
      if (a[i] == mx) {
        if ((i - 1 > 0 && a[i - 1] < mx) || (i + 1 <= n && a[i + 1] < mx)) {
          ans = i;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
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
