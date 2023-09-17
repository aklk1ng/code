#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 10;
#define ll long long
const int N = 2e5 + 10;

int a[N], tmp[N];

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cin >> tmp[i];
  }
  ll ans = 0;
  for (int i = 1; i <= n - k + 1; i++) {
    sort(tmp + 1 + i, tmp + 1 + n - k + 1);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int tt;
  // cin >> tt;
  // while (tt--) {
  //   solve();
  // }
  solve();
  return 0;
}
