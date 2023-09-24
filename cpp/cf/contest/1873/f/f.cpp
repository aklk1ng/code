#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 2e5 + 5;

ll a[N], h[N];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  int ans = 0;
  int l = 1, r = 1;
  int t = 0;
  while (r <= n) {
    if (l != r && h[r - 1] % h[r]) {
      t = a[r];
      l = r;
      r++;
    } else {
      t += a[r];
      r++;
    }
    while (t > k && l <= r) {
      t -= a[l];
      l++;
    }
    ans = max(ans, r - l);
  }
  cout << ans << '\n';
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
