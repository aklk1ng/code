#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(m);
  for (int i = 0; i < m; i++) {
    std::cin >> x[i];
    x[i]--;
  }

  std::vector<ll> v(n + 1);
  auto dist = [&](int from, int to) {
    if (from <= to) {
      return to - from;
    } else {
      return to + n - from;
    }
  };
  auto add = [&](int from, int to, int num) {
    if (from <= to) {
      v[from] += num;
      v[to] -= num;
    } else {
      v[from] += num;
      v[n] -= num;
      v[0] += num;
      v[to] -= num;
    }
  };

  for (int i = 0; i < m - 1; i++) {
    add(x[i], x[i + 1], dist(x[i + 1], x[i]));
    add(x[i + 1], x[i], dist(x[i], x[i + 1]));
  }
  ll ans = 1LL << 60;
  for (int i = 0; i < n; i++) {
    v[i + 1] += v[i];
    ans = std::min(ans, v[i]);
  }
  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T = 1;
  if (false) {
    std::cin >> T;
  }
  while (T--) {
    solve();
  }

  return 0;
}
