#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
#define ll long long
const int N = 2e5 + 5;

ll a[N];

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll l = 0, r = 3e9;
  while (l + 1 != r) {
    ll mid = l + (r - l) / 2;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      if (mid > a[i]) {
        sum += mid - a[i];
      }
    }
    if (sum <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << '\n';
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
