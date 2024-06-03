#include <bits/stdc++.h>
typedef long long ll;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, ll> m;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    m[x]++;
  }

  ll ans = 0;
  int sum = 0;
  for (auto &[k, v] : m) {
    if (v >= 3) {
      ans += v * (v - 1) * (v - 2) / 6;
    }
    if (v >= 2) {
      ans += v * (v - 1) / 2 * sum;
    }
    sum += v;
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
