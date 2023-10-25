#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l = 0;
  set<ll> sum;
  for (int i = 0; i < n; i++) {
    l += a[i];
    sum.insert(l);
  }

  ll ans = 0;
  ll r = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum.erase(l);
    l -= a[i];
    r += a[i];
    if (sum.count(r)) {
      ans = max(ans, r);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
    solve();
  return 0;
}
