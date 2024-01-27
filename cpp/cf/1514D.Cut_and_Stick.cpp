#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  std::vector v(n + 1, std::vector<int>());
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    v[a[i]].push_back(i);
  }
  std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  while (q--) {
    int l, r, ans = 1;
    std::cin >> l >> r;
    for (int i = 0; i < 40; i++) {
      int c = a[std::uniform_int_distribution<int>(l, r)(rng)];
      int f = std::upper_bound(v[c].begin(), v[c].end(), r) -
              std::lower_bound(v[c].begin(), v[c].end(), l);
      ans = std::max(ans, 2 * f - (r - l + 1));
    }
    std::cout << ans << '\n';
  }
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
