#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> track(n + 5), sum(n + 5);
  std::vector<std::pair<ll, std::pair<ll, ll>>> trav;
  std::vector<ll> pref(n + 5), dp(n + 5);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    sum[i] = sum[i - 1] + i;
    trav.push_back({x - i, {i, 0}});
    dp[i] = std::min(dp[i - 1] + 1, (ll)x);
    pref[i] = pref[i - 1] + dp[i];
  }
  int q;
  std::cin >> q;
  std::vector<ll> ans(q + 5);
  for (int i = 1; i <= q; i++) {
    int p, x;
    std::cin >> p >> x;
    x = std::min(dp[p - 1] + 1, (ll)x);
    trav.push_back({x - p, {p, i}});
  }

  std::set<ll> vis;
  vis.insert(n + 1);
  std::sort(trav.begin(), trav.end());
  for (auto &e : trav) {
    if (e.second.second) {
      auto r = *vis.upper_bound(e.second.first);
      ans[e.second.second] =
          pref[e.second.first - 1] + track[r] + sum[r - e.second.first] +
          (e.first + e.second.first - 1) * (r - e.second.first);
    } else {
      auto r = *vis.lower_bound(e.second.first);
      vis.insert(e.second.first);
      track[e.second.first] =
          track[r] + sum[r - e.second.first] +
          (e.first + e.second.first - 1) * (r - e.second.first);
    }
  }
  for (int i = 1; i <= q; i++) {
    std::cout << ans[i] << '\n';
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
