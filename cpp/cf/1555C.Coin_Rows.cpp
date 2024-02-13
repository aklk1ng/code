#include <bits/stdc++.h>
typedef long long ll;
const int INF = 2e9 + 9;

void solve() {
  int n;
  std::cin >> n;
  std::vector a(2, std::vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }

  int ans = INF;
  int sum1 = std::accumulate(a[0].begin(), a[0].end(), 0), sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum1 -= a[0][i];
    ans = std::min(ans, std::max(sum1, sum2));
    sum2 += a[1][i];
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
