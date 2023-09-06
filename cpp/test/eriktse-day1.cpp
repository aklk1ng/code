// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e8;
#define ll long long
const int N = 1e5 + 5;
ll a[N], w[N], prefix[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }

  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + (a[i] ? -1 : 1) * w[i];
  }

  ll ess = 0;
  for (int i = 1; i <= n; i++) {
    ess += a[i] * w[i];
  }
  // ll mi = 0, fix = 0;
  // for (int i = 1; i <= n; i++) {
  //   fix = max(fix, prefix[i] - mi);
  //   mi = min(mi, prefix[i]);
  // }
  ll mx = 0, fix = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(0LL, mx + (a[i] ? -1 : 1) * w[i]);
    fix = max(fix, mx);
  }
  cout << ess + fix << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
