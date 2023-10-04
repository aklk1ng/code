#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), pre(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n; i++) {
    pre[i] = (i ? pre[i - 1] : 0) + a[i];
  }

  while (q--) {
    ll x;
    cin >> x;
    ll l = 1, r = n, ans = -1;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (pre[mid - 1] >= x) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << "\n";
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
