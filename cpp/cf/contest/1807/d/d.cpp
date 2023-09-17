#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 2e5 + 5;

ll a[N], suffix[N];
int n, q;

void solve() {
  cin >> n >> q;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    suffix[i] = suffix[i - 1] + a[i];
  }

  while (q--) {
    ll l, r, k;
    cin >> l >> r >> k;
    ll ans = suffix[n] - (suffix[r] - suffix[l - 1]) + k * (r - l + 1);
    if (ans & 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
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
