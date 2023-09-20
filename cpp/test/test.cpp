#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
#define ll long long
const int N = 1e7 + 5;
const int mod = 1e9 + 7;

ll fac[N], invfac[N];

ll qmi(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll inv(ll x) { return qmi(x, mod - 2); }

ll C(ll n, ll m) {
  if (n < 0 || m < 0 || n < m) {
    return 0;
  }
  return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= 1e7; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  invfac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; i--) {
    invfac[i] = invfac[i + 1] * (i + 1) % mod;
  }
}

void solve() {
  ll q, a, b, c, n, m;
  cin >> q >> a >> b >> c;
  cin >> n >> m;
  ll sum = 0;
  for (int i = 1; i <= q; i++) {
    sum = (sum + C(n, m)) % mod;
    n = (n * a + b) % c;
    m = (m * b + a) % c;
  }
  cout << sum << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init(1e7);
  // int tt;
  // cin >> tt;
  // while (tt--) {
  //   solve();
  // }
  solve();

  return 0;
}
