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

  int sum = std::accumulate(a.begin(), a.end(), 0);
  int ans = INT_MIN;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i + 1]) {
      if (a[i] == 1) {
        ans = std::max(ans, sum - 4);
      } else {
        ans = std::max(ans, sum + 4);
      }
    } else {
      ans = std::max(ans, sum);
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
