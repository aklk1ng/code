#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n, m;
  std::cin >> n >> m;
  m *= 2;
  std::vector<std::pair<ll, ll>> diff;
  std::vector<ll> x(n + 1), p(n + 1);
  std::pair<ll, ll> key = {0, -0x3f3f3f3f3f3f3f3f};

  auto get = [&](std::pair<ll, ll> p1,
                 std::pair<ll, ll> p2) -> std::pair<ll, ll> {
    ll tx = std::max(p1.first + p1.second, p2.first + p2.second);
    ll ty = std::max(p1.second - p1.first, p2.second - p2.first);
    return {(tx - ty) / 2, (tx + ty) / 2};
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> p[i];
    x[i] *= 2;
    p[i] *= 2;
    diff.push_back({x[i] - p[i], 1});
    diff.push_back({x[i], -2});
    diff.push_back({x[i] + p[i], 1});
  }
  std::sort(diff.begin(), diff.end());
  ll a = 0, d = 0, lst = 0;
  for (auto &e : diff) {
    if (e.first != lst) {
      a += (e.first - lst) * d;
      lst = e.first;
      if (a > m) {
        key = get(key, {e.first, a - m});
      }
    }
    d += e.second;
  }
  for (int i = 1; i <= n; i++) {
    if (get(key, {x[i], p[i]}) == std::pair<ll, ll>(x[i], p[i])) {
      std::cout << 1;
    } else {
      std::cout << 0;
    }
  }
  std::cout << '\n';
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
