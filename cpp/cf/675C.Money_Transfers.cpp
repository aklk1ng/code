#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::map<ll, int> m;
  ll sum = 0;
  int ans = n - 1;
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    sum += t;
    m[sum]++;
    ans = std::min(ans, n - m[sum]);
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
