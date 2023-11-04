#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;
  ll g = 0;
  for (int i = 0; i < n; i++) {
    ll x = 0;
    cin >> x;
    g = __gcd(g, x);
  }

  int ans = 0;
  for (int i = 1; i * 1LL * i <= g; i++) {
    if (g % i == 0) {
      ans++;
      if (i != g / i) {
        ans++;
      }
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
