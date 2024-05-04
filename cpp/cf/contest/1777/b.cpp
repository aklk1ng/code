#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

std::vector<ll> fa(N);

void init() {
  fa[0] = 1;
  for (int i = 1; i < N; i++) {
    fa[i] = fa[i - 1] * i;
    fa[i] %= mod;
  }
}

void solve() {
  int n;
  std::cin >> n;

  ll ans = 1LL * n * (n - 1);
  ans %= mod;
  ans = (ans * fa[n]) % mod;
  std::cout << ans << '\n';
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
