#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 2e5 + 5;

int a[N];

void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int len = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= q) {
      len++;
    } else {
      if (len >= k) {
        ans += 1LL * (len - k + 1) * (len - k + 2) / 2;
      }
      len = 0;
    }
  }
  if (len >= k) {
    ans += 1LL * (len - k + 1) * (len - k + 2) / 2;
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
