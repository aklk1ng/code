#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<std::pair<int, int>> b(n + 1);
  for (int i = 1; i <= n; i++) {
    b[i] = {a[i], i};
  }
  std::sort(b.begin() + 1, b.end());
  std::set<int> so = {0, n + 1}, si = {0, n + 1};
  for (int i = 1; i <= n; i++) {
    si.emplace(i);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (ll)(i - 1) * (n - i + 1);
  }
  for (int i = 1; i <= n; i++) {
    int id = b[i].second;
    si.erase(id);
    so.emplace(id);

    int x2 = *si.lower_bound(id);
    int x1 = *std::prev(si.lower_bound(id));
    if (x2 == n + 1) {
      continue;
    }
    int x3 = *so.lower_bound(x2);
    ans -= (ll)(id - x1) * (x3 - x2);
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
