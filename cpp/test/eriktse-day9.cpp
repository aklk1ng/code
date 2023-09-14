// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 2e6 + 5;
const ll p = 998244353;

ll qmi(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % p;
    }
    a = a * a % p;
    b >>= 1;
  }
  return res;
}

ll inv(ll x) { return qmi(x, p - 2); }

ll f(ll a, ll b, ll c, ll x) { return (a * x % p + b) % p * inv(c * x % p) % p; }

void solve() {
  ll a, b, c, q;
  cin >> a >> b >> c >> q;
  while (q--) {
    ll x;
    cin >> x;
    cout << f(a, b, c, x) << '\n';
  }
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
  // solve();

  return 0;
}
