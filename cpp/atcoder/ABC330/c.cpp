#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll d;
  cin >> d;
  ll ans = d;
  for (ll x = 0; x < (ll)sqrt(d) + 5; x++) {
    ll z = d - x * x;
    if (z <= 0) {
      ans = min(ans, -z);
    } else {
      ll y1 = (ll)sqrt(z);
      ll y2 = y1 + 1;
      ans = min({ans, z - y1 * y1, y2 * y2 - z});
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
