#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

std::unordered_map<ll, ll> npos, spos;

void init() {
  npos[0] = 1;
  spos[0] = 0;
}

ll cal(ll n) {
  if (npos[n] != 0) {
    return spos[n];
  }
  if (n % 2 == 1) {
    cal(n / 2);
    npos[n] = npos[n / 2];
    spos[n] = spos[n / 2] * 2 + npos[n / 2];
    spos[n] %= mod;
  } else {
    cal(n / 2);
    cal(n / 2 - 1);
    npos[n] = npos[n / 2] + npos[n / 2 - 1];
    spos[n] = (spos[n / 2] + spos[n / 2 - 1]) * 2;
    spos[n] %= mod;
  }
  return spos[n];
}

void solve() {
  ll n, m;
  std::cin >> n >> m;

  if (m == 2) {
    std::cout << cal(n) << '\n';
  } else if (m == 1) {
    std::cout << n % mod << '\n';
  } else if (n % 2 == 0) {
    std::cout << (((n / 2) % mod) * ((n / 2 + 1) % mod)) % mod << '\n';
  } else {
    std::cout << (((n / 2 + 1) % mod) * ((n / 2 + 1) % mod)) % mod << '\n';
  }
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
