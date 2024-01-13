#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  ll t = 0, ans = 0, sum = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    sum += x;
    mx = max(mx, sum);
    if (sum - mx < t) {
      t = sum - mx;
      ans = mx;
    }
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
