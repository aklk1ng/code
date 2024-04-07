#include <bits/stdc++.h>
typedef long long ll;
const int mod = 998244353;

std::vector<ll> fact(1, 1);

ll pow(ll x, ll p) {
  if (!p) {
    return 1;
  }
  if (p % 2 == 0) {
    ll y = pow(x, p / 2);
    return (y * y) % mod;
  }
  return (x * pow(x, p - 1)) % mod;
}

ll inv(ll x) { return pow(x, mod - 2); }

ll cnk(ll n, ll k) {
  ll res = fact[n];
  res = (res * inv(fact[k])) % mod;
  res = (res * inv(fact[n - k])) % mod;
  return res;
}

ll cal(int n1, int n2, int n3, int n4) {
  return (cnk(n1 + n3 - 1, n3) * cnk(n2 + n4 - 1, n4)) % mod;
}

void init() {
  for (int i = 1; i <= 4e6; i++) {
    fact.push_back((fact.back() * i) % mod);
  }
}

void solve() {
  int n1, n2, n3, n4;
  std::cin >> n1 >> n2 >> n3 >> n4;
  if (n1 + n2 == 0) {
    std::cout << (n3 == 0 || n4 == 0 ? 1 : 0) << '\n';
    return;
  }
  if (std::abs(n1 - n2) > 1) {
    std::cout << "0\n";
    return;
  }

  ll ans = 0;
  if (n1 <= n2) {
    ans += cal(n1 + 1, n2, n3, n4);
  }
  if (n2 <= n1) {
    ans += cal(n1, n2 + 1, n3, n4);
  }

  std::cout << ans % mod << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (true) {
    std::cin >> T;
  }
  init();
  while (T--) {
    solve();
  }

  return 0;
}
