// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 2e5 + 5;
ll a[N], b[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  ll ans1 = 0;
  for (int i = 1; i <= n; i++) {
    ans1 += a[i] * b[i];
  }
  ll ans2 = 0;
  for (int i = 1; i <= n; i++) {
    ans2 += a[i] * b[n + 1 - i];
  }
  cout << ans2 << ' ' << ans1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }
  solve();

  return 0;
}
