#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 1e13;

void solve() {
  ll n;
  std::cin >> n;

  std::vector<ll> fac;
  ll t = 6, num = 4;
  while (t <= INF) {
    fac.push_back(t);
    t *= num;
    num++;
  }
  auto get = [&](ll a) { return 63 - __builtin_clzll(a); };
  auto cnt = [&](ll a) { return __builtin_popcountll(a); };
  std::vector<std::pair<ll, ll>> sum(1 << fac.size());
  sum[0] = {0, 0};
  for (int mask = 1; mask < (1 << fac.size()); mask++) {
    auto bit = get(mask);
    sum[mask].first = sum[mask ^ (1 << bit)].first + fac[bit];
    sum[mask].second = cnt(mask);
  }
  ll ans = cnt(n);
  for (auto &[k, v] : sum) {
    if (k <= n) {
      ans = std::min(ans, v + cnt(n - k));
    }
  }
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
  while (T--) {
    solve();
  }

  return 0;
}
